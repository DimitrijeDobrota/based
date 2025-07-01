#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::I64;
using based::trait::IsSame;

// NOLINTBEGIN(*magic-number*)

TEST_CASE("I64", "[integral/types/I64]")
{
  I64 a = 300_i64;
  I64 b = 400_i64;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(I64 x) { { +x } -> IsSame<I64>; });
    REQUIRE(+a == 300_i64);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(I64 x) { { -x } -> IsSame<I64>; });
    REQUIRE(-a == -300_i64);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(I64 x) { { ++x } -> IsSame<I64&>; });
    I64 c = a;
    I64& ref = ++c;
    REQUIRE(c == 301_i64);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(I64 x) { { x++ } -> IsSame<I64>; });
    I64 c = a;
    I64 old = c++;
    REQUIRE(c == 301_i64);
    REQUIRE(old == 300_i64);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(I64 x) { { --x } -> IsSame<I64&>; });
    I64 c = b;
    I64& ref = --c;
    REQUIRE(c == 399_i64);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(I64 x) { { x-- } -> IsSame<I64>; });
    I64 c = b;
    I64 old = c--;
    REQUIRE(c == 399_i64);
    REQUIRE(old == 400_i64);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 300_i64);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 300_i64);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs + rhs
      } -> IsSame<I64>;
    });
    REQUIRE(a + b == 700_i64);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs - rhs
      } -> IsSame<I64>;
    });
    REQUIRE(b - a == 100_i64);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs * rhs
      } -> IsSame<I64>;
    });
    REQUIRE(a * b == 120000_i64);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs / rhs
      } -> IsSame<I64>;
    });
    REQUIRE(b / a == 1_i64);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs % rhs
      } -> IsSame<I64>;
    });
    REQUIRE(b % a == 100_i64);
    REQUIRE(a % b == 300_i64);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs += rhs
      } -> IsSame<I64&>;
    });
    I64 c = a;
    c += b;
    REQUIRE(c == 700_i64);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs -= rhs
      } -> IsSame<I64&>;
    });
    I64 c = b;
    c -= a;
    REQUIRE(c == 100_i64);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs *= rhs
      } -> IsSame<I64&>;
    });
    I64 c = a;
    c *= b;
    REQUIRE(c == 120000_i64);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs /= rhs
      } -> IsSame<I64&>;
    });
    I64 c = b;
    c /= a;
    REQUIRE(c == 1_i64);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(I64 lhs, I64 rhs) {
      {
        lhs %= rhs
      } -> IsSame<I64&>;
    });
    I64 c = a;
    c %= b;
    REQUIRE(c == 300_i64);
  }
}

// NOLINTEND(*magic-number*)