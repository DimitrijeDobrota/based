#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/enum/enum.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/comparable/equality.hpp"
#include "based/concepts/comparable/greater.hpp"
#include "based/concepts/comparable/greater_equal.hpp"
#include "based/concepts/comparable/less.hpp"
#include "based/concepts/comparable/less_equal.hpp"
#include "based/concepts/is/invocable.hpp"
#include "based/concepts/is/same.hpp"
#include "based/types/types.hpp"

struct test
{
  BASED_DECLARE_ENUM(var, based::bu8, 0, a, b, c)

  [[nodiscard]] int get_var(var::enum_type req) const;

private:
  int m_a = 1;
  int m_b = 2;
  int m_c = 3;
};

BASED_DEFINE_ENUM_CLASS(test, var, based::bu8, 0, a, b, c)

inline int test::get_var(var::enum_type req) const
{
  switch (req()) {
    case var::a():
      return m_a;
    case var::b():
      return m_b;
    case var::c():
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
  STATIC_REQUIRE(test::var::enum_type::size == 3);
  STATIC_REQUIRE(test::var::a() == 0);
  STATIC_REQUIRE(test::var::b() == 1);
  STATIC_REQUIRE(test::var::c() == 2);
}

TEST_CASE("safety", "[enum/enum]")
{
  const test crnt;

  REQUIRE(crnt.get_var(test::var::a) == 1);
  REQUIRE(crnt.get_var(test::var::b) == 2);
  REQUIRE(crnt.get_var(test::var::c) == 3);

  REQUIRE(!based::Invocable<decltype(&test::get_var), based::bu8>);
  REQUIRE(!based::Invocable<decltype(&test::get_var), int>);
}

TEST_CASE("names", "[enum/enum]")
{
  REQUIRE(std::strcmp(test::var::enum_type::names[test::var::a], "a") == 0);
  REQUIRE(std::strcmp(test::var::enum_type::names[test::var::b], "b") == 0);
  REQUIRE(std::strcmp(test::var::enum_type::names[test::var::c], "c") == 0);
}

TEST_CASE("operations", "[enum/enum]")
{
  using based::SameAs;

  STATIC_REQUIRE(based::EqualityComparable<test::var::enum_type>);
  STATIC_REQUIRE(!based::LessComparable<test::var::enum_type>);
  STATIC_REQUIRE(!based::GreaterComparable<test::var::enum_type>);
  STATIC_REQUIRE(!based::LessEqualComparable<test::var::enum_type>);
  STATIC_REQUIRE(!based::GreaterEqualComparable<test::var::enum_type>);
}
