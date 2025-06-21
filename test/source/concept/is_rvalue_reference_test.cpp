#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_rvalue_reference.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsRValueRefence", "[concept/IsRValueRefence]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsRValueRef<int&&>);
  STATIC_REQUIRE(based::trait::IsRValueRef<int(&&)[2]>);
  STATIC_REQUIRE(based::trait::IsRValueRef<volatile int&&>);
  STATIC_REQUIRE(based::trait::IsRValueRef<volatile int(&&)[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const int&>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const int>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const int[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const volatile int&>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const volatile int>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const volatile int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<const volatile int[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<int&>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<int>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<int[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<int(int)>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<volatile int&>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<volatile int>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<volatile int(&)[2]>);
  STATIC_REQUIRE(not based::trait::IsRValueRef<volatile int[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
