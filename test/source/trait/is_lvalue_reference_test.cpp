#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_lvalue_reference.hpp"

TEST_CASE("IsLvalueReference", "[concept/IsLvalueReference]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(!based::trait::IsLvalueReference<int>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<int&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<int&&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<int[2]>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<int(&)[2]>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<int(&&)[2]>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<const int>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<const int&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<const int[2]>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<const int(&)[2]>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<int(int)>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<volatile int>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<volatile int&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<volatile int&&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<volatile int[2]>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<volatile int(&)[2]>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<volatile int(&&)[2]>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<const volatile int>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<const volatile int&>);
  STATIC_REQUIRE(!based::trait::IsLvalueReference<const volatile int[2]>);
  STATIC_REQUIRE(based::trait::IsLvalueReference<const volatile int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
