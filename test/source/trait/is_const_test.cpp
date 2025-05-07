#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/const.hpp"

TEST_CASE("is_const", "[trait/is_const]")
{
  // clang-format off
  struct test {};

  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(!based::is_const_v<int>);
  STATIC_REQUIRE(!based::is_const_v<int&>);
  STATIC_REQUIRE(!based::is_const_v<int&&>);
  STATIC_REQUIRE(!based::is_const_v<int[2]>);
  STATIC_REQUIRE(!based::is_const_v<int(&)[2]>);
  STATIC_REQUIRE(!based::is_const_v<int(&&)[2]>);
  STATIC_REQUIRE(based::is_const_v<const int>);
  STATIC_REQUIRE(!based::is_const_v<const int&>);
  STATIC_REQUIRE(based::is_const_v<const int[2]>);
  STATIC_REQUIRE(!based::is_const_v<const int(&)[2]>);
  STATIC_REQUIRE(!based::is_const_v<int(int)>);
  STATIC_REQUIRE(!based::is_const_v<volatile int>);
  STATIC_REQUIRE(!based::is_const_v<volatile int&>);
  STATIC_REQUIRE(!based::is_const_v<volatile int&&>);
  STATIC_REQUIRE(!based::is_const_v<volatile int[2]>);
  STATIC_REQUIRE(!based::is_const_v<volatile int(&)[2]>);
  STATIC_REQUIRE(!based::is_const_v<volatile int(&&)[2]>);
  STATIC_REQUIRE(based::is_const_v<const volatile int>);
  STATIC_REQUIRE(!based::is_const_v<const volatile int&>);
  STATIC_REQUIRE(based::is_const_v<const volatile int[2]>);
  STATIC_REQUIRE(!based::is_const_v<const volatile int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
