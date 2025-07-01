#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"

using namespace based::literals; // NOLINT(*namespace*)

using based::I8;
using based::trait::IsSame;

// NOLINTBEGIN(*magic-number*)

TEST_CASE("I8", "[integral/types/I8]")
{
  I8 a = 3_i8;
  I8 b = 4_i8;

  SECTION("unary plus")
  {
    STATIC_REQUIRE(requires(I8 x) { { +x } -> IsSame<I8>; });
    REQUIRE(+a == 3_i8);
  }
  SECTION("unary minus")
  {
    STATIC_REQUIRE(requires(I8 x) { { -x } -> IsSame<I8>; });
    REQUIRE(-a == -3_i8);
  }
  SECTION("pre-increment")
  {
    STATIC_REQUIRE(requires(I8 x) { { ++x } -> IsSame<I8&>; });
    I8 c = a;
    I8& ref = ++c;
    REQUIRE(c == 4_i8);
    REQUIRE(&ref == &c);
  }
  SECTION("post-increment")
  {
    STATIC_REQUIRE(requires(I8 x) { { x++ } -> IsSame<I8>; });
    I8 c = a;
    I8 old = c++;
    REQUIRE(c == 4_i8);
    REQUIRE(old == 3_i8);
  }
  SECTION("pre-decrement")
  {
    STATIC_REQUIRE(requires(I8 x) { { --x } -> IsSame<I8&>; });
    I8 c = b;
    I8& ref = --c;
    REQUIRE(c == 3_i8);
    REQUIRE(&ref == &c);
  }
  SECTION("post-decrement")
  {
    STATIC_REQUIRE(requires(I8 x) { { x-- } -> IsSame<I8>; });
    I8 c = b;
    I8 old = c--;
    REQUIRE(c == 3_i8);
    REQUIRE(old == 4_i8);
  }
  SECTION("operator==")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs == rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a == 3_i8);
    REQUIRE_FALSE(a == b);
  }
  SECTION("operator<=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs <= rhs
      } -> IsSame<bool>;
    });
    REQUIRE(a <= b);
    REQUIRE(a <= 3_i8);
    REQUIRE_FALSE(b <= a);
  }
  SECTION("operator+")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs + rhs
      } -> IsSame<I8>;
    });
    REQUIRE(a + b == 7_i8);
  }
  SECTION("operator-")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs - rhs
      } -> IsSame<I8>;
    });
    REQUIRE(b - a == 1_i8);
  }
  SECTION("operator*")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs * rhs
      } -> IsSame<I8>;
    });
    REQUIRE(a * b == 12_i8);
  }
  SECTION("operator/")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs / rhs
      } -> IsSame<I8>;
    });
    REQUIRE(b / a == 1_i8);
  }
  SECTION("operator%")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs % rhs
      } -> IsSame<I8>;
    });
    REQUIRE(b % a == 1_i8);
    REQUIRE(a % b == 3_i8);
  }
  SECTION("operator+=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs += rhs
      } -> IsSame<I8&>;
    });
    I8 c = a;
    c += b;
    REQUIRE(c == 7_i8);
  }
  SECTION("operator-=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs -= rhs
      } -> IsSame<I8&>;
    });
    I8 c = b;
    c -= a;
    REQUIRE(c == 1_i8);
  }
  SECTION("operator*=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs *= rhs
      } -> IsSame<I8&>;
    });
    I8 c = a;
    c *= b;
    REQUIRE(c == 12_i8);
  }
  SECTION("operator/=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs /= rhs
      } -> IsSame<I8&>;
    });
    I8 c = b;
    c /= a;
    REQUIRE(c == 1_i8);
  }
  SECTION("operator%=")
  {
    STATIC_REQUIRE(requires(I8 lhs, I8 rhs) {
      {
        lhs %= rhs
      } -> IsSame<I8&>;
    });
    I8 c = a;
    c %= b;
    REQUIRE(c == 3_i8);
  }
}

// NOLINTEND(*magic-number*)