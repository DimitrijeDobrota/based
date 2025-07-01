#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::U16;
using based::trait::IsSame;


// NOLINTBEGIN(*magic-number*)

TEST_CASE("U16", "[integral/types/U16]")
{
  U16 a = 30_u16;
  U16 b = 40_u16;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(U16 x) { { +x } -> IsSame<U16>; });
    REQUIRE(+a == 30_u16);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(U16 x) { { -x } -> IsSame<U16>; });
    REQUIRE(-a == -30_u16);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(U16 x) { { ++x } -> IsSame<U16&>; });
    U16 c = a;
    U16& ref = ++c;
    REQUIRE(c == 31_u16);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(U16 x) { { x++ } -> IsSame<U16>; });
    U16 c = a;
    U16 old = c++;
    REQUIRE(c == 31_u16);
    REQUIRE(old == 30_u16);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(U16 x) { { --x } -> IsSame<U16&>; });
    U16 c = b;
    U16& ref = --c;
    REQUIRE(c == 39_u16);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(U16 x) { { x-- } -> IsSame<U16>; });
    U16 c = b;
    U16 old = c--;
    REQUIRE(c == 39_u16);
    REQUIRE(old == 40_u16);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 30_u16);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 30_u16);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs + rhs
      } -> IsSame<U16>;
    });
    REQUIRE(a + b == 70_u16);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs - rhs
      } -> IsSame<U16>;
    });
    REQUIRE(b - a == 10_u16);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs * rhs
      } -> IsSame<U16>;
    });
    REQUIRE(a * b == 1200_u16);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs / rhs
      } -> IsSame<U16>;
    });
    REQUIRE(b / a == 1_u16);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs % rhs
      } -> IsSame<U16>;
    });
    REQUIRE(b % a == 10_u16);
    REQUIRE(a % b == 30_u16);
  }
  SECTION("operator&")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs & rhs
      } -> IsSame<U16>;
    });
    REQUIRE((0b1100_u16 & 0b1010_u16) == 0b1000_u16);
  }
  SECTION("operator|")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs | rhs
      } -> IsSame<U16>;
    });
    REQUIRE((0b1100_u16 | 0b1010_u16) == 0b1110_u16);
  }
  SECTION("operator^")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs ^ rhs
      } -> IsSame<U16>;
    });
    REQUIRE((0b1100_u16 ^ 0b1010_u16) == 0b0110_u16);
  }
  SECTION("operator<<")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs << rhs
      } -> IsSame<U16>;
    });
    REQUIRE((1_u16 << 3_u16) == 8_u16);
  }
  SECTION("operator>>")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs >> rhs
      } -> IsSame<U16>;
    });
    REQUIRE((8_u16 >> 3_u16) == 1_u16);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs += rhs
      } -> IsSame<U16&>;
    });
    U16 c = a;
    c += b;
    REQUIRE(c == 70_u16);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs -= rhs
      } -> IsSame<U16&>;
    });
    U16 c = b;
    c -= a;
    REQUIRE(c == 10_u16);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs *= rhs
      } -> IsSame<U16&>;
    });
    U16 c = a;
    c *= b;
    REQUIRE(c == 1200_u16);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs /= rhs
      } -> IsSame<U16&>;
    });
    U16 c = b;
    c /= a;
    REQUIRE(c == 1_u16);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs %= rhs
      } -> IsSame<U16&>;
    });
    U16 c = a;
    c %= b;
    REQUIRE(c == 30_u16);
  }
  SECTION("operator&=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs &= rhs
      } -> IsSame<U16&>;
    });
    U16 c = 0b1100_u16;
    c &= 0b1010_u16;
    REQUIRE(c == 0b1000_u16);
  }
  SECTION("operator|=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs |= rhs
      } -> IsSame<U16&>;
    });
    U16 c = 0b1100_u16;
    c |= 0b1010_u16;
    REQUIRE(c == 0b1110_u16);
  }
  SECTION("operator^=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs ^= rhs
      } -> IsSame<U16&>;
    });
    U16 c = 0b1100_u16;
    c ^= 0b1010_u16;
    REQUIRE(c == 0b0110_u16);
  }
  SECTION("operator<<=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs <<= rhs
      } -> IsSame<U16&>;
    });
    U16 c = 1_u16;
    c <<= 3_u16;
    REQUIRE(c == 8_u16);
  }
  SECTION("operator>>=")
  {
    STATIC_REQUIRE(requires(U16 lhs, U16 rhs) {
      {
        lhs >>= rhs
      } -> IsSame<U16&>;
    });
    U16 c = 8_u16;
    c >>= 3_u16;
    REQUIRE(c == 1_u16);
  }
}

// NOLINTEND(*magic-number*)