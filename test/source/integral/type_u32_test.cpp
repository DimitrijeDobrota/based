#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::U32;
using based::trait::IsSame;

// NOLINTBEGIN(*magic-number*)

TEST_CASE("U32", "[integral/types/U32]")
{
  U32 a = 300_u32;
  U32 b = 400_u32;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(U32 x) { { +x } -> IsSame<U32>; });
    REQUIRE(+a == 300_u32);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(U32 x) { { -x } -> IsSame<U32>; });
    REQUIRE(-a == -300_u32);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(U32 x) { { ++x } -> IsSame<U32&>; });
    U32 c = a;
    U32& ref = ++c;
    REQUIRE(c == 301_u32);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(U32 x) { { x++ } -> IsSame<U32>; });
    U32 c = a;
    U32 old = c++;
    REQUIRE(c == 301_u32);
    REQUIRE(old == 300_u32);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(U32 x) { { --x } -> IsSame<U32&>; });
    U32 c = b;
    U32& ref = --c;
    REQUIRE(c == 399_u32);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(U32 x) { { x-- } -> IsSame<U32>; });
    U32 c = b;
    U32 old = c--;
    REQUIRE(c == 399_u32);
    REQUIRE(old == 400_u32);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 300_u32);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 300_u32);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs + rhs
      } -> IsSame<U32>;
    });
    REQUIRE(a + b == 700_u32);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs - rhs
      } -> IsSame<U32>;
    });
    REQUIRE(b - a == 100_u32);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs * rhs
      } -> IsSame<U32>;
    });
    REQUIRE(a * b == 120000_u32);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs / rhs
      } -> IsSame<U32>;
    });
    REQUIRE(b / a == 1_u32);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs % rhs
      } -> IsSame<U32>;
    });
    REQUIRE(b % a == 100_u32);
    REQUIRE(a % b == 300_u32);
  }
  SECTION("operator&")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs & rhs
      } -> IsSame<U32>;
    });
    REQUIRE((0b1100_u32 & 0b1010_u32) == 0b1000_u32);
  }
  SECTION("operator|")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs | rhs
      } -> IsSame<U32>;
    });
    REQUIRE((0b1100_u32 | 0b1010_u32) == 0b1110_u32);
  }
  SECTION("operator^")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs ^ rhs
      } -> IsSame<U32>;
    });
    REQUIRE((0b1100_u32 ^ 0b1010_u32) == 0b0110_u32);
  }
  SECTION("operator<<")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs << rhs
      } -> IsSame<U32>;
    });
    REQUIRE((1_u32 << 3_u32) == 8_u32);
  }
  SECTION("operator>>")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs >> rhs
      } -> IsSame<U32>;
    });
    REQUIRE((8_u32 >> 3_u32) == 1_u32);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs += rhs
      } -> IsSame<U32&>;
    });
    U32 c = a;
    c += b;
    REQUIRE(c == 700_u32);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs -= rhs
      } -> IsSame<U32&>;
    });
    U32 c = b;
    c -= a;
    REQUIRE(c == 100_u32);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs *= rhs
      } -> IsSame<U32&>;
    });
    U32 c = a;
    c *= b;
    REQUIRE(c == 120000_u32);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs /= rhs
      } -> IsSame<U32&>;
    });
    U32 c = b;
    c /= a;
    REQUIRE(c == 1_u32);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs %= rhs
      } -> IsSame<U32&>;
    });
    U32 c = a;
    c %= b;
    REQUIRE(c == 300_u32);
  }
  SECTION("operator&=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs &= rhs
      } -> IsSame<U32&>;
    });
    U32 c = 0b1100_u32;
    c &= 0b1010_u32;
    REQUIRE(c == 0b1000_u32);
  }
  SECTION("operator|=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs |= rhs
      } -> IsSame<U32&>;
    });
    U32 c = 0b1100_u32;
    c |= 0b1010_u32;
    REQUIRE(c == 0b1110_u32);
  }
  SECTION("operator^=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs ^= rhs
      } -> IsSame<U32&>;
    });
    U32 c = 0b1100_u32;
    c ^= 0b1010_u32;
    REQUIRE(c == 0b0110_u32);
  }
  SECTION("operator<<=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs <<= rhs
      } -> IsSame<U32&>;
    });
    U32 c = 1_u32;
    c <<= 3_u32;
    REQUIRE(c == 8_u32);
  }
  SECTION("operator>>=")
  {
    STATIC_REQUIRE(requires(U32 lhs, U32 rhs) {
      {
        lhs >>= rhs
      } -> IsSame<U32&>;
    });
    U32 c = 8_u32;
    c >>= 3_u32;
    REQUIRE(c == 1_u32);
  }
}

// NOLINTEND(*magic-number*)