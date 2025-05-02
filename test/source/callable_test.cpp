// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/type_traits.hpp"


namespace
{

// NOLINTNEXTLINE(*need*)
int free_func(int a, double b)
{
  return static_cast<int>(a + b);
}

}  // namespace

using based::SameAs;

TEST_CASE("free function", "[type_traits/callable]")
{
  using type_t = decltype(free_func);

  STATIC_REQUIRE(based::Callable<type_t>);
  STATIC_REQUIRE(SameAs<based::callable_sig_t<type_t>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::callable_ret_t<type_t>, int>);
}

TEST_CASE("lambda", "[type_traits/callable]")
{
  const auto func = [](int a, double b)
  {
    return static_cast<int>(a + b);
  };
  using type_t = decltype(func);

  STATIC_REQUIRE(based::Callable<type_t>);
  STATIC_REQUIRE(SameAs<based::callable_sig_t<type_t>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::callable_ret_t<type_t>, int>);
}

/*
struct func
{
  auto operator()(auto a, auto b) { return static_cast<int>(a + b); }
};

TEST_CASE("member function", "[type_traits/callable]")
{
  // [&](auto&&... args) -> decltype(auto) { return
  // f(std::forward<decltype(args)>(args)...); }

  // based::error_template<decltype(&func::template operator()<int, double>)>();
  STATIC_REQUIRE(based::Callable<func>);
  STATIC_REQUIRE(SameAs<based::callable_sig_t<func>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::callable_ret_t<func>, int>);
}
*/
