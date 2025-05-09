#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/enum/enum.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/comparable/equality.hpp"
#include "based/concepts/comparable/greater.hpp"
#include "based/concepts/comparable/greater_equal.hpp"
#include "based/concepts/comparable/less.hpp"
#include "based/concepts/comparable/less_equal.hpp"
#include "based/concepts/is/same.hpp"
#include "based/types/types.hpp"

struct test
{
  BASED_ENUM_DECLARE(var, based::u8, a, b, c)

  [[nodiscard]] int get_var(var::type req) const;

private:
  int m_a = 1;
  int m_b = 2;
  int m_c = 3;
};

BASED_DEFINE_CLASS_ENUM(test, var, based::u8, a, b, c)

inline int test::get_var(var::type req) const
{
  switch (req.value) {
    case var::a.value:
      return m_a;
    case var::b.value:
      return m_b;
    case var::c.value:
      return m_c;
    default:
      return -1;
  }
}

TEST_CASE("types", "[enum/enum]")
{
  STATIC_REQUIRE(requires { typename test::var; });
  STATIC_REQUIRE(requires { test::var::a; });
  STATIC_REQUIRE(requires { test::var::b; });
  STATIC_REQUIRE(requires { test::var::c; });
}

TEST_CASE("safety", "[enum/enum]")
{
  const test crnt;

  STATIC_REQUIRE(requires { crnt.get_var(test::var::a) == 1; });
  STATIC_REQUIRE(requires { crnt.get_var(test::var::b) == 2; });
  STATIC_REQUIRE(requires { crnt.get_var(test::var::c) == 3; });
}

TEST_CASE("names", "[enum/enum]")
{
  REQUIRE(std::strcmp(test::var::type::names[test::var::a], "a") == 0);
  REQUIRE(std::strcmp(test::var::type::names[test::var::b], "b") == 0);
  REQUIRE(std::strcmp(test::var::type::names[test::var::c], "c") == 0);
}

TEST_CASE("operations", "[enum/enum]")
{
  using based::SameAs;

  STATIC_REQUIRE(based::EqualityComparable<test::var::type>);
  STATIC_REQUIRE(!based::LessComparable<test::var::type>);
  STATIC_REQUIRE(!based::GreaterComparable<test::var::type>);
  STATIC_REQUIRE(!based::LessEqualComparable<test::var::type>);
  STATIC_REQUIRE(!based::GreaterEqualComparable<test::var::type>);
}
