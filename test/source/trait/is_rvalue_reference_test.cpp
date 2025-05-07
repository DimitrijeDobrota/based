#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/rvalue_reference.hpp"

TEST_CASE("is_rvalue_reference", "[trait/is_rvalue_reference]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(!based::is_rvalue_reference_v<int>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<int&>);
  STATIC_REQUIRE(based::is_rvalue_reference_v<int&&>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<int[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<int(&)[2]>);
  STATIC_REQUIRE(based::is_rvalue_reference_v<int(&&)[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const int>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const int&>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const int[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const int(&)[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<int(int)>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<volatile int>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<volatile int&>);
  STATIC_REQUIRE(based::is_rvalue_reference_v<volatile int&&>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<volatile int[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<volatile int(&)[2]>);
  STATIC_REQUIRE(based::is_rvalue_reference_v<volatile int(&&)[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const volatile int>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const volatile int&>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const volatile int[2]>);
  STATIC_REQUIRE(!based::is_rvalue_reference_v<const volatile int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
