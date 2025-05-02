// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/type_traits.hpp"

namespace
{

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
  STATIC_REQUIRE(SameAs<based::sig_t<type_t>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::ret_t<type_t>, int>);
}

TEST_CASE("lambda", "[type_traits/callable]")
{
  const auto func = [](int a, double b)
  {
    return static_cast<int>(a + b);
  };
  using type_t = decltype(func);

  STATIC_REQUIRE(based::Callable<type_t>);
  STATIC_REQUIRE(SameAs<based::sig_t<type_t>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::ret_t<type_t>, int>);
}

TEST_CASE("member function", "[type_traits/callable]")
{
  struct func
  {
    int operator()(int a, double b) { return static_cast<int>(a + b); }
  };

  STATIC_REQUIRE(based::Callable<func>);
  STATIC_REQUIRE(SameAs<based::sig_t<func>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::ret_t<func>, int>);
}
