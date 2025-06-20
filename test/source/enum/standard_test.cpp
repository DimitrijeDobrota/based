#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/invocable.hpp"
#include "based/enum/enum.hpp"
#include "based/integral/types.hpp"

struct Test
{
  BASED_ENUM_STANDARD(var, based::I8) {
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

BASED_ENUM_TRAITS_STANDARD(Test::var, based::I8)

inline int Test::get_var(var req) const
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
  STATIC_REQUIRE(requires { typename Test::var; });

  STATIC_REQUIRE(requires { Test::var::a; });
  STATIC_REQUIRE(requires { Test::var::b; });
  STATIC_REQUIRE(requires { Test::var::c; });
  STATIC_REQUIRE(requires { Test::var::min; });
  STATIC_REQUIRE(requires { Test::var::max; });
  STATIC_REQUIRE(requires { Test::var::none; });
}

TEST_CASE("safety", "[enum/standard]")
{
  const Test crnt;

  REQUIRE(crnt.get_var(Test::var::a) == 1);
  REQUIRE(crnt.get_var(Test::var::b) == 2);
  REQUIRE(crnt.get_var(Test::var::c) == 3);

  REQUIRE(!based::Invocable<decltype(&Test::get_var), based::U8>);
  REQUIRE(!based::Invocable<decltype(&Test::get_var), int>);
}
