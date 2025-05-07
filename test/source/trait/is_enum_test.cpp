#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/enum.hpp"

TEST_CASE("is_enum", "[trait/is_enum]")
{
  // clang-format off
	struct a { enum e {}; };
	enum e {};
	enum class ec : int {};

	STATIC_REQUIRE(!based::is_enum_v<a>);
	STATIC_REQUIRE(based::is_enum_v<a::e>);
	STATIC_REQUIRE(based::is_enum_v<e>);
	STATIC_REQUIRE(based::is_enum_v<ec>);
	STATIC_REQUIRE(!based::is_enum_v<int>);
  // clang-format !on
}
