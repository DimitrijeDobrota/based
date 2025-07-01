#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::U8;
using based::trait::IsSame;

// NOLINTBEGIN(*magic-number*)

TEST_CASE("U8", "[integral/types/U8]")
{
  U8 a = 10_u8;
  U8 b = 20_u8;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(U8 x) { { +x } -> IsSame<U8>; });
    REQUIRE(+a == 10_u8);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(U8 x) { { -x } -> IsSame<U8>; });
    REQUIRE(-a == -10_u8);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(U8 x) { { ++x } -> IsSame<U8&>; });
    U8 c = a;
    U8& ref = ++c;
    REQUIRE(c == 11_u8);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(U8 x) { { x++ } -> IsSame<U8>; });
    U8 c = a;
    U8 old = c++;
    REQUIRE(c == 11_u8);
    REQUIRE(old == 10_u8);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(U8 x) { { --x } -> IsSame<U8&>; });
    U8 c = b;
    U8& ref = --c;
    REQUIRE(c == 19_u8);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(U8 x) { { x-- } -> IsSame<U8>; });
    U8 c = b;
    U8 old = c--;
    REQUIRE(c == 19_u8);
    REQUIRE(old == 20_u8);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 10_u8);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 10_u8);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs + rhs
      } -> IsSame<U8>;
    });
    REQUIRE(a + b == 30_u8);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs - rhs
      } -> IsSame<U8>;
    });
    REQUIRE(b - a == 10_u8);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs * rhs
      } -> IsSame<U8>;
    });
    REQUIRE(a * b == 200_u8);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs / rhs
      } -> IsSame<U8>;
    });
    REQUIRE(b / a == 2_u8);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs % rhs
      } -> IsSame<U8>;
    });
    REQUIRE(b % a == 0_u8);
    REQUIRE(a % b == 10_u8);
  }
  SECTION("operator&")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs & rhs
      } -> IsSame<U8>;
    });
    REQUIRE((0b1100_u8 & 0b1010_u8) == 0b1000_u8);
  }
  SECTION("operator|")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs | rhs
      } -> IsSame<U8>;
    });
    REQUIRE((0b1100_u8 | 0b1010_u8) == 0b1110_u8);
  }
  SECTION("operator^")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs ^ rhs
      } -> IsSame<U8>;
    });
    REQUIRE((0b1100_u8 ^ 0b1010_u8) == 0b0110_u8);
  }
  SECTION("operator<<")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs << rhs
      } -> IsSame<U8>;
    });
    REQUIRE((1_u8 << 3_u8) == 8_u8);
  }
  SECTION("operator>>")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs >> rhs
      } -> IsSame<U8>;
    });
    REQUIRE((8_u8 >> 3_u8) == 1_u8);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs += rhs
      } -> IsSame<U8&>;
    });
    U8 c = a;
    c += b;
    REQUIRE(c == 30_u8);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs -= rhs
      } -> IsSame<U8&>;
    });
    U8 c = b;
    c -= a;
    REQUIRE(c == 10_u8);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs *= rhs
      } -> IsSame<U8&>;
    });
    U8 c = a;
    c *= b;
    REQUIRE(c == 200_u8);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs /= rhs
      } -> IsSame<U8&>;
    });
    U8 c = b;
    c /= a;
    REQUIRE(c == 2_u8);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs %= rhs
      } -> IsSame<U8&>;
    });
    U8 c = a;
    c %= b;
    REQUIRE(c == 10_u8);
  }
  SECTION("operator&=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs &= rhs
      } -> IsSame<U8&>;
    });
    U8 c = 0b1100_u8;
    c &= 0b1010_u8;
    REQUIRE(c == 0b1000_u8);
  }
  SECTION("operator|=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs |= rhs
      } -> IsSame<U8&>;
    });
    U8 c = 0b1100_u8;
    c |= 0b1010_u8;
    REQUIRE(c == 0b1110_u8);
  }
  SECTION("operator^=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs ^= rhs
      } -> IsSame<U8&>;
    });
    U8 c = 0b1100_u8;
    c ^= 0b1010_u8;
    REQUIRE(c == 0b0110_u8);
  }
  SECTION("operator<<=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs <<= rhs
      } -> IsSame<U8&>;
    });
    U8 c = 1_u8;
    c <<= 3_u8;
    REQUIRE(c == 8_u8);
  }
  SECTION("operator>>=")
  {
    STATIC_REQUIRE(requires(U8 lhs, U8 rhs) {
      {
        lhs >>= rhs
      } -> IsSame<U8&>;
    });
    U8 c = 8_u8;
    c >>= 3_u8;
    REQUIRE(c == 1_u8);
  }
}

// NOLINTEND(*magic-number*)