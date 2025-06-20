#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_rvalue_reference.hpp"

TEST_CASE("IsRvalueReference", "[concept/IsRvalueReference]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(!based::trait::IsRvalueReference<int>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<int&>);
  STATIC_REQUIRE(based::trait::IsRvalueReference<int&&>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<int[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<int(&)[2]>);
  STATIC_REQUIRE(based::trait::IsRvalueReference<int(&&)[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const int>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const int&>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const int[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const int(&)[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<int(int)>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<volatile int>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<volatile int&>);
  STATIC_REQUIRE(based::trait::IsRvalueReference<volatile int&&>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<volatile int[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<volatile int(&)[2]>);
  STATIC_REQUIRE(based::trait::IsRvalueReference<volatile int(&&)[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const volatile int>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const volatile int&>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const volatile int[2]>);
  STATIC_REQUIRE(!based::trait::IsRvalueReference<const volatile int(&)[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
