#include "based/type_traits.hpp"

struct irregular
{
  irregular() = default;

  irregular(const irregular&) = delete;
  irregular(irregular&&) = delete;

  irregular& operator=(const irregular&) = delete;
  irregular& operator=(irregular&&) = delete;

  ~irregular() = default;
};

template<typename T>
struct identity
{
  T operator()(T val) { return val; }
};

template<typename T, typename U>
struct add
{
  T operator()(T val1, U val2) { return val1 + val2; }
};

int main()
{
  using id = identity<double>;
  using ii = identity<irregular>;

  static_assert(std::same_as<based::domain_t<id>, std::tuple<double>>);
  static_assert(std::same_as<based::codomain_t<id>, double>);
  static_assert(based::arity_v<id> == 1);

  static_assert(based::Procedure<id>);
  static_assert(based::Procedure<ii>);

  static_assert(based::RegularProcedure<id>);
  static_assert(!based::RegularProcedure<ii>);

  using ad = add<double, double>;
  using ai = add<irregular, irregular>;
  using aid = add<irregular, double>;
  using adi = add<double, irregular>;

  static_assert(std::same_as<based::domain_t<ad>, std::tuple<double, double>>);
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

  static const auto l1 = [](double a) { return a; };
  static_assert(based::RegularProcedure<decltype(l1)>);

  static const auto l2 = [](irregular /* a */) { return 1; };
  static_assert(!based::RegularProcedure<decltype(l2)>);
}
