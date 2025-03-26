#include "based/type_traits.hpp"

namespace
{

struct irregular
{
  irregular() = default;

  irregular(const irregular&) = delete;
  irregular(irregular&&) = delete;

  irregular& operator=(const irregular&) = delete;
  irregular& operator=(irregular&&) = delete;

  ~irregular() = default;
};

struct no_return
{
  void operator()() {}
};

template<typename T>
struct identity
{
  T operator()(T val) { return val; }
};

template<typename T, typename U>
struct add
{
  T operator()(const T& val1, const U& val2) { return val1 + val2; }
};

template<typename T>
struct mutate
{
  T operator()(T* val) { return *val = 1; }
};

template<typename T, typename U>
T sub(T val1, U val2)
{
  return val1 - val2;
}

}  // namespace

int main()
{
  static_assert(based::arity_v<no_return> == 0);
  static_assert(based::Procedure<no_return>);
  static_assert(!based::RegularProcedure<no_return>);
  static_assert(!based::FunctionalProcedure<no_return>);

  using id = identity<double>;
  using ii = identity<irregular>;

  static_assert(std::same_as<based::domain_t<id>, std::tuple<double>>);
  static_assert(std::same_as<based::codomain_t<id>, double>);
  static_assert(based::arity_v<id> == 1);

  static_assert(based::Procedure<id>);
  static_assert(based::Procedure<ii>);

  static_assert(based::RegularProcedure<id>);
  static_assert(!based::RegularProcedure<ii>);

  static_assert(based::FunctionalProcedure<id>);
  static_assert(!based::FunctionalProcedure<ii>);

  using ad = add<double, double>;
  using ai = add<irregular, irregular>;
  using aid = add<irregular, double>;
  using adi = add<double, irregular>;

  static_assert(std::same_as<based::domain_t<ad>,
                             std::tuple<const double&, const double&>>);
  static_assert(std::same_as<based::codomain_t<ad>, double>);
  static_assert(based::arity_v<ad> == 2);

  static_assert(based::Procedure<ad>);
  static_assert(based::Procedure<ai>);
  static_assert(based::Procedure<aid>);
  static_assert(based::Procedure<adi>);

  static_assert(based::RegularProcedure<ad>);
  static_assert(!based::RegularProcedure<ai>);
  static_assert(!based::RegularProcedure<aid>);
  static_assert(!based::RegularProcedure<adi>);

  static_assert(based::FunctionalProcedure<ad>);
  static_assert(!based::FunctionalProcedure<ai>);
  static_assert(!based::FunctionalProcedure<aid>);
  static_assert(!based::FunctionalProcedure<adi>);

  using md = mutate<double>;

  static_assert(based::Procedure<md>);
  static_assert(based::RegularProcedure<md>);
  static_assert(!based::FunctionalProcedure<md>);

  static_assert(based::RegularProcedure<decltype(sub<double, double>)>);

  static const auto l1 = [](double a) { return a; };
  static_assert(based::Procedure<decltype(l1)>);
  static_assert(based::RegularProcedure<decltype(l1)>);
  static_assert(based::FunctionalProcedure<decltype(l1)>);

  static const auto l2 = [](irregular /* a */) { return 1; };
  static_assert(based::Procedure<decltype(l2)>);
  static_assert(!based::RegularProcedure<decltype(l2)>);
  static_assert(!based::FunctionalProcedure<decltype(l2)>);

  return 0;
}
