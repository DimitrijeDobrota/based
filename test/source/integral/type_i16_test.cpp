#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::I16;
using based::trait::IsSame;


// NOLINTBEGIN(*magic-number*)

TEST_CASE("I16", "[integral/types/I16]")
{
  I16 a = 30_i16;
  I16 b = 40_i16;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(I16 x) { { +x } -> IsSame<I16>; });
    REQUIRE(+a == 30_i16);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(I16 x) { { -x } -> IsSame<I16>; });
    REQUIRE(-a == -30_i16);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(I16 x) { { ++x } -> IsSame<I16&>; });
    I16 c = a;
    I16& ref = ++c;
    REQUIRE(c == 31_i16);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(I16 x) { { x++ } -> IsSame<I16>; });
    I16 c = a;
    I16 old = c++;
    REQUIRE(c == 31_i16);
    REQUIRE(old == 30_i16);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(I16 x) { { --x } -> IsSame<I16&>; });
    I16 c = b;
    I16& ref = --c;
    REQUIRE(c == 39_i16);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(I16 x) { { x-- } -> IsSame<I16>; });
    I16 c = b;
    I16 old = c--;
    REQUIRE(c == 39_i16);
    REQUIRE(old == 40_i16);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 30_i16);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 30_i16);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs + rhs
      } -> IsSame<I16>;
    });
    REQUIRE(a + b == 70_i16);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs - rhs
      } -> IsSame<I16>;
    });
    REQUIRE(b - a == 10_i16);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs * rhs
      } -> IsSame<I16>;
    });
    REQUIRE(a * b == 1200_i16);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs / rhs
      } -> IsSame<I16>;
    });
    REQUIRE(b / a == 1_i16);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs % rhs
      } -> IsSame<I16>;
    });
    REQUIRE(b % a == 10_i16);
    REQUIRE(a % b == 30_i16);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs += rhs
      } -> IsSame<I16&>;
    });
    I16 c = a;
    c += b;
    REQUIRE(c == 70_i16);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs -= rhs
      } -> IsSame<I16&>;
    });
    I16 c = b;
    c -= a;
    REQUIRE(c == 10_i16);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs *= rhs
      } -> IsSame<I16&>;
    });
    I16 c = a;
    c *= b;
    REQUIRE(c == 1200_i16);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs /= rhs
      } -> IsSame<I16&>;
    });
    I16 c = b;
    c /= a;
    REQUIRE(c == 1_i16);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(I16 lhs, I16 rhs) {
      {
        lhs %= rhs
      } -> IsSame<I16&>;
    });
    I16 c = a;
    c %= b;
    REQUIRE(c == 30_i16);
  }
}

// NOLINTEND(*magic-number*)