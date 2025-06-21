#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_enum.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsEnum", "[concept/IsEnum]")
{
  // clang-format off
	struct A { enum e {}; };
	enum e {};
	enum class ec : int {};

	STATIC_REQUIRE(based::trait::IsEnum<A::e>);
	STATIC_REQUIRE(based::trait::IsEnum<e>);
	STATIC_REQUIRE(based::trait::IsEnum<ec>);
	STATIC_REQUIRE(not based::trait::IsEnum<A>);
	STATIC_REQUIRE(not based::trait::IsEnum<int>);
  // clang-format not on
}
