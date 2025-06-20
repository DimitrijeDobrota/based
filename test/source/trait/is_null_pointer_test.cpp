#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_null_pointer.hpp"

TEST_CASE("IsNullPointer", "[concept/IsNullPointer]")
{
  double const test = 0;

  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsNullPointer<decltype(nullptr)>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<void>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<const void>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<volatile void>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<void*>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<int>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<decltype(test)>);
  STATIC_REQUIRE(!based::trait::IsNullPointer<void>);
  // NOLINTEND(*array*)
  // clang-format on
}
