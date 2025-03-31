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

// NOLINTBEGIN move-const-arg

TEST_CASE("min(move, literal) = left", "[based/algorithm/min]")
{
  int a = 3;
  REQUIRE(std::same_as<int&&, decltype(based::min(std::move(a), 4))>);
  REQUIRE(based::min(std::move(a), 4) == 3);
}

TEST_CASE("min(move, literal) = right", "[based/algorithm/min]")
{
  int a = 4;
  REQUIRE(std::same_as<int&&, decltype(based::min(std::move(a), 3))>);
  REQUIRE(based::min(std::move(a), 3) == 3);
}

TEST_CASE("min(move, value) = left", "[based/algorithm/min]")
{
  int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, value) = right", "[based/algorithm/min]")
{
  int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = left", "[based/algorithm/min]")
{
  int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = right", "[based/algorithm/min]")
{
  int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(literal, move) = left", "[based/algorithm/min]")
{
  int b = 4;
  REQUIRE(std::same_as<int&&, decltype(based::min(3, std::move(b)))>);
  REQUIRE(based::min(3, std::move(b)) == 3);
}

TEST_CASE("min(literal, move) = right", "[based/algorithm/min]")
{
  int b = 3;
  REQUIRE(std::same_as<int&&, decltype(based::min(4, std::move(b)))>);
  REQUIRE(based::min(4, std::move(b)) == 3);
}

TEST_CASE("min(value, move) = left", "[based/algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(value, move) = right", "[based/algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(const value, move) = left", "[based/algorithm/min]")
{
  const int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(const value, move) = right", "[based/algorithm/min]")
{
  const int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(move, move) = left", "[based/algorithm/min]")
{
  int a = 3;
  int b = 4;
  REQUIRE(
      std::same_as<int&&, decltype(based::min(std::move(a), std::move(b)))>);
  REQUIRE(based::min(std::move(a), std::move(b)) == 3);
}

TEST_CASE("min(move, move) = right", "[based/algorithm/min]")
{
  int a = 4;
  int b = 3;
  REQUIRE(
      std::same_as<int&&, decltype(based::min(std::move(a), std::move(b)))>);
  REQUIRE(based::min(std::move(a), std::move(b)) == 3);
}

// NOLINTEND move-const-arg

TEST_CASE("min-stability", "[based/algorithm/min]")
{
  using type_t = std::pair<int, int>;

  static const auto cmp = [](const type_t& x, const type_t& y)
  { return x.first < y.first; };

  const type_t a = {3, 4};
  const type_t b = {3, 5};

  REQUIRE(based::min(a, b, cmp).second == 4);
  REQUIRE(based::min(b, a, cmp).second == 5);
}
