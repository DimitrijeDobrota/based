#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/enum/enum_flag.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/comparable/equality.hpp"
#include "based/concepts/comparable/greater.hpp"
#include "based/concepts/comparable/greater_equal.hpp"
#include "based/concepts/comparable/less.hpp"
#include "based/concepts/comparable/less_equal.hpp"
#include "based/concepts/is/same.hpp"
#include "based/types/types.hpp"

BASED_DECLARE_ENUM_FLAG(var, based::u8, empty, a, b, c)
BASED_DEFINE_ENUM_FLAG(var, based::u8, empty, a, b, c)

TEST_CASE("types", "[enum/enum]")
{
  STATIC_REQUIRE(requires { typename var; });
  STATIC_REQUIRE(requires { var::empty; });
  STATIC_REQUIRE(requires { var::a; });
  STATIC_REQUIRE(requires { var::b; });
  STATIC_REQUIRE(requires { var::c; });
  STATIC_REQUIRE(var::type::size == 4);
  STATIC_REQUIRE(var::empty.value == 0);
  STATIC_REQUIRE(var::a.value == 1);
  STATIC_REQUIRE(var::b.value == 2);
  STATIC_REQUIRE(var::c.value == 4);
}

TEST_CASE("operations", "[enum/enum]")
{
  using based::SameAs;

  SECTION("COMPARE")
  {
    STATIC_REQUIRE(based::EqualityComparable<var::type>);
    STATIC_REQUIRE(!based::LessComparable<var::type>);
    STATIC_REQUIRE(!based::GreaterComparable<var::type>);
    STATIC_REQUIRE(!based::LessEqualComparable<var::type>);
    STATIC_REQUIRE(!based::GreaterEqualComparable<var::type>);
  }

  SECTION("functions")
  {
    const auto var1 = var::a | var::b;

    REQUIRE(var1.test(var::a));
    REQUIRE(var1.test(var::b));
    REQUIRE(!var1.test(var::c));

    const auto var2 = ~var1;

    REQUIRE(!var2.test(var::a));
    REQUIRE(!var2.test(var::b));
    REQUIRE(var2.test(var::c));

    const auto var3 = var1 & var2;

    REQUIRE(!var3.test(var::a));
    REQUIRE(!var3.test(var::b));
    REQUIRE(!var3.test(var::c));

    const auto var4 = var1 ^ var2;

    REQUIRE(var4.test(var::a));
    REQUIRE(var4.test(var::b));
    REQUIRE(var4.test(var::c));
  }
}
