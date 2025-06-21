#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_null_pointer.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsNullPointer", "[concept/IsNullPointer]")
{
  double const test = 0;

  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsNullPointer<decltype(nullptr)>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<void>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<const void>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<volatile void>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<void*>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<int>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<decltype(test)>);
  STATIC_REQUIRE(not based::trait::IsNullPointer<void>);
  // NOLINTEND(*array*)
  // clang-format on
}
