#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/class.hpp"

TEST_CASE("is_class", "[trait/is_class]")
{
  // clang-format off
  struct a {};
  class b {};
  enum class e {};
  union u { class uc {}; };

  STATIC_REQUIRE(based::is_class<a>::value);
  STATIC_REQUIRE(based::is_class_v<b>);
  STATIC_REQUIRE(!based::is_class_v<b*>);
  STATIC_REQUIRE(!based::is_class_v<b&>);
  STATIC_REQUIRE(based::is_class_v<const b>);
  STATIC_REQUIRE(!based::is_class<e>::value);
  STATIC_REQUIRE(!based::is_class_v<u>);
  STATIC_REQUIRE(based::is_class_v<u::uc>);
  STATIC_REQUIRE(!based::is_class_v<int>);
  // clang-format on
}
