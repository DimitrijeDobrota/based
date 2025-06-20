#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_array.hpp"

TEST_CASE("IsArray", "[concept/IsArray]")
{
  // clang-format off
  struct Test {};

  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(!based::trait::IsArray<Test>);
  STATIC_REQUIRE(based::trait::IsArray<Test[]>);
  STATIC_REQUIRE(based::trait::IsArray<Test[3]>);
  STATIC_REQUIRE(!based::trait::IsArray<float>);
  STATIC_REQUIRE(!based::trait::IsArray<int>);
  STATIC_REQUIRE(based::trait::IsArray<int[]>);
  STATIC_REQUIRE(based::trait::IsArray<int[3]>);
  STATIC_REQUIRE(!based::trait::IsArray<std::array<int, 3>>);
  // clang-format on
  // NOLINTEND(*array*)
}
