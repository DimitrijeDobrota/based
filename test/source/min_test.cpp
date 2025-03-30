#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("min(literal, literal)", "[based/algorithm/min]")
{
  REQUIRE(std::same_as<int, decltype(based::min(3, 4))>);
  REQUIRE(based::min(3, 4) == 3);
}

TEST_CASE("min(value, literal)", "[based/algorithm/min]")
{
  int a = 3; // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(literal, value)", "[based/algorithm/min]")
{
  int b = 4; // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(value, value)", "[based/algorithm/min]")
{
  int a = 3; // NOLINT misc-const-correctness
  int b = 4; // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, literal)", "[based/algorithm/min]")
{
  const int a = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(literal, const value)", "[based/algorithm/min]")
{
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(const value, const value)", "[based/algorithm/min]")
{
  const int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}
