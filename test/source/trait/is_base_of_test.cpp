#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/base_of.hpp"

TEST_CASE("is_base_of", "[trait/is_base_of]")
{
  // clang-format off
	class A {};
	class B : A {};
	class C : B {};
	class D {};
	union e {};
	using i = int;
 
  STATIC_REQUIRE(based::is_base_of_v<A, A>);
  STATIC_REQUIRE(based::is_base_of_v<A, B>);
  STATIC_REQUIRE(based::is_base_of_v<A, C>);
  STATIC_REQUIRE(!based::is_base_of_v<A, D>);
  STATIC_REQUIRE(!based::is_base_of_v<B, A>);
  STATIC_REQUIRE(!based::is_base_of_v<e, e>);
  STATIC_REQUIRE(!based::is_base_of_v<i, i>);
  // clang-format on
}
