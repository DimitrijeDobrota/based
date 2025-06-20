#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/null_pointer.hpp"

TEST_CASE("is_null_pointer", "[trait/is_null_pointer]")
{
  double const test = 0;

  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(based::is_null_pointer_v<decltype(nullptr)>);
  STATIC_REQUIRE(!based::is_null_pointer_v<void>);
  STATIC_REQUIRE(!based::is_null_pointer_v<const void>);
  STATIC_REQUIRE(!based::is_null_pointer_v<volatile void>);
  STATIC_REQUIRE(!based::is_null_pointer_v<void*>);
  STATIC_REQUIRE(!based::is_null_pointer_v<int>);
  STATIC_REQUIRE(!based::is_null_pointer_v<decltype(test)>);
  STATIC_REQUIRE(!based::is_null_pointer_v<std::is_null_pointer<void>>);
  // clang-format on
  // NOLINTEND(*array*)
}
