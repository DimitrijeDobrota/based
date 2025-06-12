#include "based/string/format.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("format", "[string/format]")
{
  const std::string format = "This is a {}! {}";

  SECTION("none")
  {
    const auto res = based::string_format(format);
    REQUIRE(res == "This is a {}! {}");
  }

  SECTION("one")
  {
    const auto res = based::string_format(format, "test");
    REQUIRE(res == "This is a test! {}");
  }

  SECTION("two")
  {
    const auto res = based::string_format(format, "test", "hello");
    REQUIRE(res == "This is a test! hello");
  }

  SECTION("three")
  {
    const auto res = based::string_format(format, "test", "hello", "yo");
    REQUIRE(res == "This is a test! hello");
  }
}
