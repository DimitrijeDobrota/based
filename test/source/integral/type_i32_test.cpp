#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::I32;
using based::trait::IsSame;


// NOLINTBEGIN(*magic-number*)

TEST_CASE("I32", "[integral/types/I32]")
{
  I32 a = 300_i32;
  I32 b = 400_i32;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(I32 x) { { +x } -> IsSame<I32>; });
    REQUIRE(+a == 300_i32);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(I32 x) { { -x } -> IsSame<I32>; });
    REQUIRE(-a == -300_i32);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(I32 x) { { ++x } -> IsSame<I32&>; });
    I32 c = a;
    I32& ref = ++c;
    REQUIRE(c == 301_i32);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(I32 x) { { x++ } -> IsSame<I32>; });
    I32 c = a;
    I32 old = c++;
    REQUIRE(c == 301_i32);
    REQUIRE(old == 300_i32);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(I32 x) { { --x } -> IsSame<I32&>; });
    I32 c = b;
    I32& ref = --c;
    REQUIRE(c == 399_i32);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(I32 x) { { x-- } -> IsSame<I32>; });
    I32 c = b;
    I32 old = c--;
    REQUIRE(c == 399_i32);
    REQUIRE(old == 400_i32);
  }

  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 300_i32);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 300_i32);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs + rhs
      } -> IsSame<I32>;
    });
    REQUIRE(a + b == 700_i32);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs - rhs
      } -> IsSame<I32>;
    });
    REQUIRE(b - a == 100_i32);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs * rhs
      } -> IsSame<I32>;
    });
    REQUIRE(a * b == 120000_i32);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs / rhs
      } -> IsSame<I32>;
    });
    REQUIRE(b / a == 1_i32);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs % rhs
      } -> IsSame<I32>;
    });
    REQUIRE(b % a == 100_i32);
    REQUIRE(a % b == 300_i32);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs += rhs
      } -> IsSame<I32&>;
    });
    I32 c = a;
    c += b;
    REQUIRE(c == 700_i32);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs -= rhs
      } -> IsSame<I32&>;
    });
    I32 c = b;
    c -= a;
    REQUIRE(c == 100_i32);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs *= rhs
      } -> IsSame<I32&>;
    });
    I32 c = a;
    c *= b;
    REQUIRE(c == 120000_i32);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs /= rhs
      } -> IsSame<I32&>;
    });
    I32 c = b;
    c /= a;
    REQUIRE(c == 1_i32);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(I32 lhs, I32 rhs) {
      {
        lhs %= rhs
      } -> IsSame<I32&>;
    });
    I32 c = a;
    c %= b;
    REQUIRE(c == 300_i32);
  }
}

// NOLINTEND(*magic-number*)