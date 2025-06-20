#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/trait/is/class.hpp"

TEST_CASE("is_class", "[trait/is_class]")
{
  // clang-format off
  struct A {};
  class B {};
  enum class e {};
  union u { class Uc {}; };

  STATIC_REQUIRE(based::is_class_v<A>);
  STATIC_REQUIRE(based::is_class_v<B>);
  STATIC_REQUIRE(!based::is_class_v<B*>);
  STATIC_REQUIRE(!based::is_class_v<B&>);
  STATIC_REQUIRE(based::is_class_v<const B>);
  STATIC_REQUIRE(!based::is_class_v<e>);
  STATIC_REQUIRE(!based::is_class_v<u>);
  STATIC_REQUIRE(based::is_class_v<u::Uc>);
  STATIC_REQUIRE(!based::is_class_v<int>);
  // clang-format on
}
