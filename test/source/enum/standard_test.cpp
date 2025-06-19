#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/invocable.hpp"
#include "based/enum/enum.hpp"
#include "based/integral/types.hpp"

struct test
{
  BASED_ENUM_STANDARD(var, based::i8) {
    a,
    b,
    c,
    min = a,
    max = c,
    none = -1,
  };

  [[nodiscard]] int get_var(var req) const;

private:
  int m_a = 1;
  int m_b = 2;
  int m_c = 3;
};

BASED_ENUM_TRAITS_STANDARD(test::var, based::u8)

inline int test::get_var(var req) const
{
  switch (based::enumeration::enum_cast<var>(req)) {
    case var::a:
      return m_a;
    case var::b:
      return m_b;
    case var::c:
      return m_c;
    case var::none:
      return -1;
  }
}

TEST_CASE("types", "[enum/standard]")
{
  STATIC_REQUIRE(requires { typename test::var; });

  STATIC_REQUIRE(requires { test::var::a; });
  STATIC_REQUIRE(requires { test::var::b; });
  STATIC_REQUIRE(requires { test::var::c; });
  STATIC_REQUIRE(requires { test::var::min; });
  STATIC_REQUIRE(requires { test::var::max; });
  STATIC_REQUIRE(requires { test::var::none; });
}

TEST_CASE("safety", "[enum/standard]")
{
  const test crnt;

  REQUIRE(crnt.get_var(test::var::a) == 1);
  REQUIRE(crnt.get_var(test::var::b) == 2);
  REQUIRE(crnt.get_var(test::var::c) == 3);

  REQUIRE(!based::Invocable<decltype(&test::get_var), based::u8>);
  REQUIRE(!based::Invocable<decltype(&test::get_var), int>);
}
