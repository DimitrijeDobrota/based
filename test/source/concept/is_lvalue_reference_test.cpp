#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_lvalue_reference.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsLValueReference", "[concept/IsLValueReference]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsLValueRef<const int&>);
  STATIC_REQUIRE(based::trait::IsLValueRef<const int(&)[2]>);
  STATIC_REQUIRE(based::trait::IsLValueRef<const volatile int&>);
  STATIC_REQUIRE(based::trait::IsLValueRef<const volatile int(&)[2]>);
  STATIC_REQUIRE(based::trait::IsLValueRef<int&>);
  STATIC_REQUIRE(based::trait::IsLValueRef<int(&)[2]>);
  STATIC_REQUIRE(based::trait::IsLValueRef<volatile int&>);
  STATIC_REQUIRE(based::trait::IsLValueRef<volatile int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<const int>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<const int[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<const volatile int>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<const volatile int[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<int&&>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<int>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<int(&&)[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<int[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<int(int)>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<volatile int&&>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<volatile int>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<volatile int(&&)[2]>);
  STATIC_REQUIRE(not based::trait::IsLValueRef<volatile int[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
