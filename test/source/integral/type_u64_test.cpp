#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::U64;
using based::trait::IsSame;

// NOLINTBEGIN(*magic-number*)

TEST_CASE("U64", "[integral/types/U64]")
{
  U64 a = 300_u64;
  U64 b = 400_u64;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(U64 x) { { +x } -> IsSame<U64>; });
    REQUIRE(+a == 300_u64);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(U64 x) { { -x } -> IsSame<U64>; });
    REQUIRE(-a == -300_u64);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(U64 x) { { ++x } -> IsSame<U64&>; });
    U64 c = a;
    U64& ref = ++c;
    REQUIRE(c == 301_u64);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(U64 x) { { x++ } -> IsSame<U64>; });
    U64 c = a;
    U64 old = c++;
    REQUIRE(c == 301_u64);
    REQUIRE(old == 300_u64);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(U64 x) { { --x } -> IsSame<U64&>; });
    U64 c = b;
    U64& ref = --c;
    REQUIRE(c == 399_u64);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(U64 x) { { x-- } -> IsSame<U64>; });
    U64 c = b;
    U64 old = c--;
    REQUIRE(c == 399_u64);
    REQUIRE(old == 400_u64);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 300_u64);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 300_u64);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs + rhs
      } -> IsSame<U64>;
    });
    REQUIRE(a + b == 700_u64);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs - rhs
      } -> IsSame<U64>;
    });
    REQUIRE(b - a == 100_u64);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs * rhs
      } -> IsSame<U64>;
    });
    REQUIRE(a * b == 120000_u64);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs / rhs
      } -> IsSame<U64>;
    });
    REQUIRE(b / a == 1_u64);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs % rhs
      } -> IsSame<U64>;
    });
    REQUIRE(b % a == 100_u64);
    REQUIRE(a % b == 300_u64);
  }
  SECTION("operator&")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs & rhs
      } -> IsSame<U64>;
    });
    REQUIRE((0b1100_u64 & 0b1010_u64) == 0b1000_u64);
  }
  SECTION("operator|")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs | rhs
      } -> IsSame<U64>;
    });
    REQUIRE((0b1100_u64 | 0b1010_u64) == 0b1110_u64);
  }
  SECTION("operator^")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs ^ rhs
      } -> IsSame<U64>;
    });
    REQUIRE((0b1100_u64 ^ 0b1010_u64) == 0b0110_u64);
  }
  SECTION("operator<<")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs << rhs
      } -> IsSame<U64>;
    });
    REQUIRE((1_u64 << 3_u64) == 8_u64);
  }
  SECTION("operator>>")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs >> rhs
      } -> IsSame<U64>;
    });
    REQUIRE((8_u64 >> 3_u64) == 1_u64);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs += rhs
      } -> IsSame<U64&>;
    });
    U64 c = a;
    c += b;
    REQUIRE(c == 700_u64);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs -= rhs
      } -> IsSame<U64&>;
    });
    U64 c = b;
    c -= a;
    REQUIRE(c == 100_u64);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs *= rhs
      } -> IsSame<U64&>;
    });
    U64 c = a;
    c *= b;
    REQUIRE(c == 120000_u64);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs /= rhs
      } -> IsSame<U64&>;
    });
    U64 c = b;
    c /= a;
    REQUIRE(c == 1_u64);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs %= rhs
      } -> IsSame<U64&>;
    });
    U64 c = a;
    c %= b;
    REQUIRE(c == 300_u64);
  }
  SECTION("operator&=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs &= rhs
      } -> IsSame<U64&>;
    });
    U64 c = 0b1100_u64;
    c &= 0b1010_u64;
    REQUIRE(c == 0b1000_u64);
  }
  SECTION("operator|=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs |= rhs
      } -> IsSame<U64&>;
    });
    U64 c = 0b1100_u64;
    c |= 0b1010_u64;
    REQUIRE(c == 0b1110_u64);
  }
  SECTION("operator^=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs ^= rhs
      } -> IsSame<U64&>;
    });
    U64 c = 0b1100_u64;
    c ^= 0b1010_u64;
    REQUIRE(c == 0b0110_u64);
  }
  SECTION("operator<<=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs <<= rhs
      } -> IsSame<U64&>;
    });
    U64 c = 1_u64;
    c <<= 3_u64;
    REQUIRE(c == 8_u64);
  }
  SECTION("operator>>=")
  {
    STATIC_REQUIRE(requires(U64 lhs, U64 rhs) {
      {
        lhs >>= rhs
      } -> IsSame<U64&>;
    });
    U64 c = 8_u64;
    c >>= 3_u64;
    REQUIRE(c == 1_u64);
  }
}

// NOLINTEND(*magic-number*)