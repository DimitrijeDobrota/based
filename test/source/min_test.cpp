#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("min(literal, literal) = left", "[based/algorithm/min]")
{
  REQUIRE(std::same_as<int&&, decltype(based::min(3, 4))>);
  REQUIRE(based::min(3, 4) == 3);
}

TEST_CASE("min(literal, literal) = right", "[based/algorithm/min]")
{
  REQUIRE(std::same_as<int&&, decltype(based::min(4, 3))>);
  REQUIRE(based::min(4, 3) == 3);
}

TEST_CASE("min(value, literal) = left", "[based/algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(value, literal) = right", "[based/algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(a, 3))>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, value) = left", "[based/algorithm/min]")
{
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, value) = right", "[based/algorithm/min]")
{
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(4, b))>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(value, value) = left", "[based/algorithm/min]")
{
  int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, value) = right", "[based/algorithm/min]")
{
  int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, literal) = left", "[based/algorithm/min]")
{
  const int a = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(const value, literal) = right", "[based/algorithm/min]")
{
  const int a = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, 3))>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, const value) = left", "[based/algorithm/min]")
{
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, const value) = right", "[based/algorithm/min]")
{
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(4, b))>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(const value, const value) = left", "[based/algorithm/min]")
{
  const int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, const value) = right", "[based/algorithm/min]")
{
  const int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = left", "[based/algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = right", "[based/algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = left", "[based/algorithm/min]")
{
  const int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = right", "[based/algorithm/min]")
{
  const int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}
