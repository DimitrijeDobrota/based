#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/void.hpp"

TEST_CASE("is_void", "[trait/is_void]")
{
  double const test = 0;

  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(based::is_void_v<void>);
  STATIC_REQUIRE(based::is_void_v<const void>);
  STATIC_REQUIRE(based::is_void_v<volatile void>);
  STATIC_REQUIRE(!based::is_void_v<void*>);
  STATIC_REQUIRE(!based::is_void_v<int>);
  STATIC_REQUIRE(!based::is_void_v<decltype(test)>);
  STATIC_REQUIRE(!based::is_void_v<std::is_void<void>>);
  // clang-format on
  // NOLINTEND(*array*)
}
