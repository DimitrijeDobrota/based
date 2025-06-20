#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_base_of.hpp"

TEST_CASE("IsBaseOf", "[concept/IsBaseOf]")
{
  // clang-format off
	class A {};
	class B : A {};
	class C : B {};
	class D {};
	union e {};
	using I = int;
 
  STATIC_REQUIRE(based::trait::IsBaseOf<A, A>);
  STATIC_REQUIRE(based::trait::IsBaseOf<A, B>);
  STATIC_REQUIRE(based::trait::IsBaseOf<A, C>);
  STATIC_REQUIRE(!based::trait::IsBaseOf<A, D>);
  STATIC_REQUIRE(!based::trait::IsBaseOf<B, A>);
  STATIC_REQUIRE(!based::trait::IsBaseOf<e, e>);
  STATIC_REQUIRE(!based::trait::IsBaseOf<I, I>);
  // clang-format on
}
