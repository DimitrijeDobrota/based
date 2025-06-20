#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_void.hpp"

TEST_CASE("IsVoid", "[concept/IsVoid]")
{
  double const test = 0;

  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(based::trait::IsVoid<void>);
  STATIC_REQUIRE(based::trait::IsVoid<const void>);
  STATIC_REQUIRE(based::trait::IsVoid<volatile void>);
  STATIC_REQUIRE(!based::trait::IsVoid<void*>);
  STATIC_REQUIRE(!based::trait::IsVoid<int>);
  STATIC_REQUIRE(!based::trait::IsVoid<decltype(test)>);
  // NOLINTEND(*array*)
  // clang-format on
}
