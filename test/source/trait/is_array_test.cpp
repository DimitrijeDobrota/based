#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/array.hpp"

TEST_CASE("is_array", "[trait/is_array]")
{
  // clang-format off
  struct test {};

  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(!based::is_array_v<test>);
  STATIC_REQUIRE(based::is_array_v<test[]>);
  STATIC_REQUIRE(based::is_array_v<test[3]>);
  STATIC_REQUIRE(!based::is_array_v<float>);
  STATIC_REQUIRE(!based::is_array_v<int>);
  STATIC_REQUIRE(based::is_array_v<int[]>);
  STATIC_REQUIRE(based::is_array_v<int[3]>);
  STATIC_REQUIRE(!based::is_array_v<std::array<int, 3>>);
  // clang-format on
  // NOLINTEND(*array*)
}
