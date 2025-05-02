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
  using id = identity<double>;
  using ii = identity<irregular>;

  static_assert(based::Procedure<id, double, double>);
  static_assert(!based::Procedure<ii, irregular>);

  static_assert(based::RegularProcedure<id, double, double>);
  static_assert(!based::RegularProcedure<ii, irregular>);

  static_assert(based::FunctionalProcedure<id, double, double>);
  static_assert(!based::FunctionalProcedure<ii, irregular>);

  using ad = add<double, double>;
  using ai = add<irregular, irregular>;
  using aid = add<irregular, double>;
  using adi = add<double, irregular>;

  static_assert(based::Procedure<ad, double, double, double>);
  static_assert(!based::Procedure<ai, irregular, irregular, irregular>);
  static_assert(!based::Procedure<aid, irregular, irregular, double>);
  static_assert(based::Procedure<adi, double, double, irregular>);

  static_assert(based::RegularProcedure<ad, double, double, double>);
  static_assert(!based::RegularProcedure<ai, irregular, irregular, irregular>);
  static_assert(!based::RegularProcedure<aid, irregular, irregular, double>);
  static_assert(!based::RegularProcedure<adi, double, double, irregular>);

  static_assert(based::FunctionalProcedure<ad, double, double, double>);
  static_assert(!based::
                    FunctionalProcedure<ai, irregular, irregular, irregular>);
  static_assert(!based::FunctionalProcedure<aid, irregular, irregular, double>);
  static_assert(!based::FunctionalProcedure<adi, double, double, irregular>);

  using md = mutate<double>;

  static_assert(based::Procedure<md, double, double*>);
  static_assert(based::RegularProcedure<md, double, double*>);
  static_assert(!based::FunctionalProcedure<md, double, double*>);

  static_assert(based::RegularProcedure<
                decltype(sub<double, double>),
                double,
                double,
                double>);

  static const auto func1 = [](double /* a */)
  {
    return 1;
  };
  static_assert(based::Procedure<decltype(func1), int, double>);
  static_assert(based::RegularProcedure<decltype(func1), int, double>);
  static_assert(based::FunctionalProcedure<decltype(func1), int, double>);

  static const auto func2 = [](irregular /* a */)
  {
    return 1;
  };
  static_assert(!based::Procedure<decltype(func2), int, irregular>);
  static_assert(!based::RegularProcedure<decltype(func2), int, irregular>);
  static_assert(!based::FunctionalProcedure<decltype(func2), int, irregular>);

  static const auto func3 = [](const irregular& /* a */)
  {
    return 1;
  };
  static_assert(based::Procedure<decltype(func3), int, irregular>);
  static_assert(!based::RegularProcedure<decltype(func3), int, irregular>);
  static_assert(!based::FunctionalProcedure<decltype(func3), int, irregular>);

  return 0;
}
