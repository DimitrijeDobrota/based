#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("min(literal, literal) = left", "[algorithm/min]")
{
  REQUIRE(std::same_as<int&&, decltype(based::min(3, 4))>);
  REQUIRE(based::min(3, 4) == 3);
}

TEST_CASE("min(literal, literal) = right", "[algorithm/min]")
{
  REQUIRE(std::same_as<int&&, decltype(based::min(4, 3))>);
  REQUIRE(based::min(4, 3) == 3);
}

TEST_CASE("min(value, literal) = left", "[algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(value, literal) = right", "[algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(a, 3))>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, value) = left", "[algorithm/min]")
{
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, value) = right", "[algorithm/min]")
{
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(4, b))>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(value, value) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, value) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, literal) = left", "[algorithm/min]")
{
  const int a = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, 4))>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(const value, literal) = right", "[algorithm/min]")
{
  const int a = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, 3))>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, const value) = left", "[algorithm/min]")
{
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(3, b))>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, const value) = right", "[algorithm/min]")
{
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(4, b))>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(const value, const value) = left", "[algorithm/min]")
{
  const int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, const value) = right", "[algorithm/min]")
{
  const int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = left", "[algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = right", "[algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = left", "[algorithm/min]")
{
  const int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = right", "[algorithm/min]")
{
  const int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::min(a, b))>);
  REQUIRE(based::min(a, b) == 3);
}

// NOLINTBEGIN move-const-arg

TEST_CASE("min(move, literal) = left", "[algorithm/min]")
{
  int a = 3;
  REQUIRE(std::same_as<int&&, decltype(based::min(std::move(a), 4))>);
  REQUIRE(based::min(std::move(a), 4) == 3);
}

TEST_CASE("min(move, literal) = right", "[algorithm/min]")
{
  int a = 4;
  REQUIRE(std::same_as<int&&, decltype(based::min(std::move(a), 3))>);
  REQUIRE(based::min(std::move(a), 3) == 3);
}

TEST_CASE("min(move, value) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, value) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = left", "[algorithm/min]")
{
  int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = right", "[algorithm/min]")
{
  int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(std::move(a), b))>);
  REQUIRE(based::min(std::move(a), b) == 3);
}

TEST_CASE("min(literal, move) = left", "[algorithm/min]")
{
  int b = 4;
  REQUIRE(std::same_as<int&&, decltype(based::min(3, std::move(b)))>);
  REQUIRE(based::min(3, std::move(b)) == 3);
}

TEST_CASE("min(literal, move) = right", "[algorithm/min]")
{
  int b = 3;
  REQUIRE(std::same_as<int&&, decltype(based::min(4, std::move(b)))>);
  REQUIRE(based::min(4, std::move(b)) == 3);
}

TEST_CASE("min(value, move) = left", "[algorithm/min]")
{
  int a = 3;  // NOLINT misc-const-correctness
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(value, move) = right", "[algorithm/min]")
{
  int a = 4;  // NOLINT misc-const-correctness
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(const value, move) = left", "[algorithm/min]")
{
  const int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(const value, move) = right", "[algorithm/min]")
{
  const int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::min(a, std::move(b)))>);
  REQUIRE(based::min(a, std::move(b)) == 3);
}

TEST_CASE("min(move, move) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;
  REQUIRE(
      std::same_as<int&&, decltype(based::min(std::move(a), std::move(b)))>);
  REQUIRE(based::min(std::move(a), std::move(b)) == 3);
}

TEST_CASE("min(move, move) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;
  REQUIRE(
      std::same_as<int&&, decltype(based::min(std::move(a), std::move(b)))>);
  REQUIRE(based::min(std::move(a), std::move(b)) == 3);
}

// NOLINTEND move-const-arg

TEST_CASE("min-stability", "[algorithm/min]")
{
  using type_t = std::pair<int, int>;

  static const auto cmp = [](const type_t& x, const type_t& y)
  { return x.first < y.first; };

  const type_t a = {3, 4};
  const type_t b = {3, 5};

  REQUIRE(based::min(a, b, cmp).second == 4);
  REQUIRE(based::min(b, a, cmp).second == 5);
}
