#include "based/string/literal.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("empty", "[string/literal]")
{
  const based::string_literal sltr = "";

  REQUIRE(sltr.size() == 0);
  REQUIRE(std::memcmp(sltr.data(), "", sltr.size()) == 0);
}

TEST_CASE("nonempty", "[string/literal]")
{
  const based::string_literal sltr = "nonempty";

  REQUIRE(sltr.size() == 8);
  REQUIRE(std::memcmp(sltr.data(), "nonempty", sltr.size()) == 0);
}

TEST_CASE("template", "[string/literal]")
{
  const auto data = []<based::string_literal l>()
  {
    return l.data();
  };

  const auto size = []<based::string_literal l>()
  {
    return l.size();
  };

  REQUIRE(size.operator()<"">() == 0);
  REQUIRE(size.operator()<"nonempty">() == 8);

  REQUIRE(std::memcmp(data.operator()<"">(), "", 0) == 0);
  REQUIRE(std::memcmp(data.operator()<"nonempty">(), "nonempty", 8) == 0);
}
