#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/base_of.hpp"

TEST_CASE("is_base_of", "[trait/is_base_of]")
{
  // clang-format off
	class a {};
	class b : a {};
	class c : b {};
	class d {};
	union e {};
	using i = int;
 
  STATIC_REQUIRE(based::is_base_of_v<a, a>);
  STATIC_REQUIRE(based::is_base_of_v<a, b>);
  STATIC_REQUIRE(based::is_base_of_v<a, c>);
  STATIC_REQUIRE(!based::is_base_of_v<a, d>);
  STATIC_REQUIRE(!based::is_base_of_v<b, a>);
  STATIC_REQUIRE(!based::is_base_of_v<e, e>);
  STATIC_REQUIRE(!based::is_base_of_v<i, i>);
  // clang-format on
}
