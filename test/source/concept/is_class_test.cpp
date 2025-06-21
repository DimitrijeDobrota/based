#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/is_class.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("IsClass", "[concept/IsClass]")
{
  // clang-format off
  struct A {};
  class B {};
  enum class e {};
  union u { class Uc {}; };

  STATIC_REQUIRE(based::trait::IsClass<A>);
  STATIC_REQUIRE(based::trait::IsClass<B>);
  STATIC_REQUIRE(based::trait::IsClass<const B>);
  STATIC_REQUIRE(based::trait::IsClass<u::Uc>);
  STATIC_REQUIRE(not based::trait::IsClass<B&>);
  STATIC_REQUIRE(not based::trait::IsClass<B*>);
  STATIC_REQUIRE(not based::trait::IsClass<e>);
  STATIC_REQUIRE(not based::trait::IsClass<int>);
  STATIC_REQUIRE(not based::trait::IsClass<u>);
  // clang-format on
}
