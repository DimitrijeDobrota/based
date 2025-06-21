#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_const.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsConst", "[concept/IsConst]")
{
  // clang-format off
  struct Test {};

  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsConst<const int>);
  STATIC_REQUIRE(based::trait::IsConst<const int[2]>);
  STATIC_REQUIRE(based::trait::IsConst<const volatile int>);
  STATIC_REQUIRE(based::trait::IsConst<const volatile int[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<const int&>);
  STATIC_REQUIRE(not based::trait::IsConst<const int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<const volatile int&>);
  STATIC_REQUIRE(not based::trait::IsConst<const volatile int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<int&&>);
  STATIC_REQUIRE(not based::trait::IsConst<int&>);
  STATIC_REQUIRE(not based::trait::IsConst<int>);
  STATIC_REQUIRE(not based::trait::IsConst<int(&&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<int[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<int(int)>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int&&>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int&>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int(&&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsConst<volatile int[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
