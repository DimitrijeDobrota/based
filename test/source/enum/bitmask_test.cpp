#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/enum/enum.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/integral/types.hpp"

BASED_ENUM_BITMASK(var, based::u8) {
    a = 1,
    b = 2,
    c = 4,
    min = 0,
    max = a | b | c,  // NOLINT
};
BASED_ENUM_TRAITS_BITMASK(var, based::u8)

TEST_CASE("types", "[enum/enum_flag]")
{
  STATIC_REQUIRE(requires { typename var; });

  STATIC_REQUIRE(requires { var::a; });
  STATIC_REQUIRE(requires { var::b; });
  STATIC_REQUIRE(requires { var::c; });
}

TEST_CASE("operations", "[enum/enum_flag]")
{
  using based::SameAs;

  SECTION("operators")
  {
    using namespace based::enumeration;  // NOLINT(*namespace*)

    SECTION("eql")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          a == b
        } -> SameAs<bool>;
      });

      STATIC_REQUIRE(requires(var a, var b) {
        {
          a != b
        } -> SameAs<bool>;
      });
    }

    SECTION("or")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          a | b
        } -> SameAs<var>;
      });

      STATIC_REQUIRE(requires(var a, var b) {
        {
          a |= b
        } -> SameAs<var&>;
      });
    }

    SECTION("and")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          a& b
        } -> SameAs<var>;
      });

      STATIC_REQUIRE(requires(var a, var b) {
        {
          a &= b
        } -> SameAs<var&>;
      });
    }

    SECTION("xor")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          a ^ b
        } -> SameAs<var>;
      });

      STATIC_REQUIRE(requires(var a, var b) {
        {
          a ^= b
        } -> SameAs<var&>;
      });
    }

    SECTION("not")
    {
      STATIC_REQUIRE(requires(var a) {
        {
          ~a
        } -> SameAs<var>;
      });
    }

    SECTION("set")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          set(a, b)
        } -> SameAs<var&>;
      });
    }

    SECTION("mask")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          mask(a, b)
        } -> SameAs<var&>;
      });
    }

    SECTION("tgl")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          tgl(a, b)
        } -> SameAs<var&>;
      });
    }

    SECTION("neg")
    {
      STATIC_REQUIRE(requires(var a) {
        {
          neg(a)
        } -> SameAs<var&>;
      });
    }

    SECTION("clear")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          clear(a, b)
        } -> SameAs<var&>;
      });
    }

    SECTION("test")
    {
      STATIC_REQUIRE(requires(var a, var b) {
        {
          test(a, b)
        } -> SameAs<bool>;
      });
    }
  }

  SECTION("functions")
  {
    using namespace based::enumeration;  // NOLINT(*namespace*)

    const auto var1 = var::a | var::b;

    REQUIRE(test(var1, var::a));
    REQUIRE(test(var1, var::b));
    REQUIRE(!test(var1, var::c));

    const auto var2 = ~var1;

    REQUIRE(!test(var2, var::a));
    REQUIRE(!test(var2, var::b));
    REQUIRE(test(var2, var::c));

    const auto var3 = var1 & var2;

    REQUIRE(!test(var3, var::a));
    REQUIRE(!test(var3, var::b));
    REQUIRE(!test(var3, var::c));

    const auto var4 = var1 ^ var2;

    REQUIRE(test(var4, var::a));
    REQUIRE(test(var4, var::b));
    REQUIRE(test(var4, var::c));
  }
}

/*
TEST_CASE("enum_flag_wrapper", "[enum/enum_flag_wrapper]")
{
  auto flags = 0_u8;
  {
    auto wrapper = based::enum_flag_wrapper<var>(flags);

    wrapper |= var::a;
    wrapper |= var::c;
  }

  REQUIRE(flags == 0x5_u8);
}
*/
