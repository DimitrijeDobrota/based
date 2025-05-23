#include <catch2/catch_test_macros.hpp>

#include "based/string/literal.hpp"

TEST_CASE("empty", "[string/string_literal]")
{
  const based::string_literal sltr = "";

  REQUIRE(sltr.size() == 1);
  REQUIRE(std::memcmp(sltr.data(), "", sltr.size()) == 0);
}

TEST_CASE("nonempty", "[string/string_literal]")
{
  const based::string_literal sltr = "nonempty";

  REQUIRE(sltr.size() == 9);
  REQUIRE(std::memcmp(sltr.data(), "nonempty", sltr.size()) == 0);
}

TEST_CASE("template", "[string/string_literal]")
{
  const auto data = []<based::string_literal l>()
  {
    return l.data();
  };

  const auto size = []<based::string_literal l>()
  {
    return l.size();
  };

  REQUIRE(size.operator()<"">() == 1);
  REQUIRE(size.operator()<"nonempty">() == 9);

  REQUIRE(std::memcmp(data.operator()<"">(), "", 1) == 0);
  REQUIRE(std::memcmp(data.operator()<"nonempty">(), "nonempty", 9) == 0);
}
