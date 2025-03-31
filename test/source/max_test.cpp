#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("max(literal, literal) = right", "[based/algorithm/max]")
{
  REQUIRE(std::same_as<int&&, decltype(based::max(3, 4))>);
  REQUIRE(based::max(3, 4) == 4);
}

TEST_CASE("max(literal, literal) = left", "[based/algorithm/max]")
{
  REQUIRE(std::same_as<int&&, decltype(based::max(4, 3))>);
  REQUIRE(based::max(4, 3) == 4);
}

TEST_CASE("max(value, literal) = right", "[based/algorithm/max]")
{
  int a = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(a, 4))>);
  REQUIRE(based::max(a, 4) == 4);
}

TEST_CASE("max(value, literal) = left", "[based/algorithm/max]")
{
  int a = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(a, 3))>);
  REQUIRE(based::max(a, 3) == 4);
}

TEST_CASE("max(literal, value) = right", "[based/algorithm/max]")
{
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(3, b))>);
  REQUIRE(based::max(3, b) == 4);
}

TEST_CASE("max(literal, value) = left", "[based/algorithm/max]")
{
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(4, b))>);
  REQUIRE(based::max(4, b) == 4);
}

TEST_CASE("max(value, value) = right", "[based/algorithm/max]")
{
  int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, value) = left", "[based/algorithm/max]")
{
  int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, literal) = right", "[based/algorithm/max]")
{
  const int a = 3;
  REQUIRE(std::same_as<int, decltype(based::max(a, 4))>);
  REQUIRE(based::max(a, 4) == 4);
}

TEST_CASE("max(const value, literal) = left", "[based/algorithm/max]")
{
  const int a = 4;
  REQUIRE(std::same_as<int, decltype(based::max(a, 3))>);
  REQUIRE(based::max(a, 3) == 4);
}

TEST_CASE("max(literal, const value) = right", "[based/algorithm/max]")
{
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::max(3, b))>);
  REQUIRE(based::max(3, b) == 4);
}

TEST_CASE("max(literal, const value) = left", "[based/algorithm/max]")
{
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::max(4, b))>);
  REQUIRE(based::max(4, b) == 4);
}

TEST_CASE("max(const value, const value) = right", "[based/algorithm/max]")
{
  const int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, const value) = left", "[based/algorithm/max]")
{
  const int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, const value) = right", "[based/algorithm/max]")
{
  int a = 3;  // NOLINT misc-const-correctness
  const int b = 4;
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, const value) = left", "[based/algorithm/max]")
{
  int a = 4;  // NOLINT misc-const-correctness
  const int b = 3;
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, value) = right", "[based/algorithm/max]")
{
  const int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, value) = left", "[based/algorithm/max]")
{
  const int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<const int&, decltype(based::max(a, b))>);
  REQUIRE(based::max(a, b) == 4);
}

// NOLINTBEGIN move-const-arg

TEST_CASE("max(move, literal) = right", "[based/algorithm/max]")
{
  int a = 3;
  REQUIRE(std::same_as<int&&, decltype(based::max(std::move(a), 4))>);
  REQUIRE(based::max(std::move(a), 4) == 4);
}

TEST_CASE("max(move, literal) = left", "[based/algorithm/max]")
{
  int a = 4;
  REQUIRE(std::same_as<int&&, decltype(based::max(std::move(a), 3))>);
  REQUIRE(based::max(std::move(a), 3) == 4);
}

TEST_CASE("max(move, value) = right", "[based/algorithm/max]")
{
  int a = 3;
  int b = 4;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(std::move(a), b))>);
  REQUIRE(based::max(std::move(a), b) == 4);
}

TEST_CASE("max(move, value) = left", "[based/algorithm/max]")
{
  int a = 4;
  int b = 3;  // NOLINT misc-const-correctness
  REQUIRE(std::same_as<int, decltype(based::max(std::move(a), b))>);
  REQUIRE(based::max(std::move(a), b) == 4);
}

TEST_CASE("max(move, const value) = right", "[based/algorithm/max]")
{
  int a = 3;
  const int b = 4;
  REQUIRE(std::same_as<int, decltype(based::max(std::move(a), b))>);
  REQUIRE(based::max(std::move(a), b) == 4);
}

TEST_CASE("max(move, const value) = left", "[based/algorithm/max]")
{
  int a = 4;
  const int b = 3;
  REQUIRE(std::same_as<int, decltype(based::max(std::move(a), b))>);
  REQUIRE(based::max(std::move(a), b) == 4);
}

TEST_CASE("max(literal, move) = right", "[based/algorithm/max]")
{
  int b = 4;
  REQUIRE(std::same_as<int&&, decltype(based::max(3, std::move(b)))>);
  REQUIRE(based::max(3, std::move(b)) == 4);
}

TEST_CASE("max(literal, move) = left", "[based/algorithm/max]")
{
  int b = 3;
  REQUIRE(std::same_as<int&&, decltype(based::max(4, std::move(b)))>);
  REQUIRE(based::max(4, std::move(b)) == 4);
}

TEST_CASE("max(value, move) = right", "[based/algorithm/max]")
{
  int a = 3;  // NOLINT misc-const-correctness
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::max(a, std::move(b)))>);
  REQUIRE(based::max(a, std::move(b)) == 4);
}

TEST_CASE("max(value, move) = left", "[based/algorithm/max]")
{
  int a = 4;  // NOLINT misc-const-correctness
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::max(a, std::move(b)))>);
  REQUIRE(based::max(a, std::move(b)) == 4);
}

TEST_CASE("max(const value, move) = right", "[based/algorithm/max]")
{
  const int a = 3;
  int b = 4;
  REQUIRE(std::same_as<int, decltype(based::max(a, std::move(b)))>);
  REQUIRE(based::max(a, std::move(b)) == 4);
}

TEST_CASE("max(const value, move) = left", "[based/algorithm/max]")
{
  const int a = 4;
  int b = 3;
  REQUIRE(std::same_as<int, decltype(based::max(a, std::move(b)))>);
  REQUIRE(based::max(a, std::move(b)) == 4);
}

TEST_CASE("max(move, move) = right", "[based/algorithm/max]")
{
  int a = 3;
  int b = 4;
  REQUIRE(
      std::same_as<int&&, decltype(based::max(std::move(a), std::move(b)))>);
  REQUIRE(based::max(std::move(a), std::move(b)) == 4);
}

TEST_CASE("max(move, move) = left", "[based/algorithm/max]")
{
  int a = 4;
  int b = 3;
  REQUIRE(
      std::same_as<int&&, decltype(based::max(std::move(a), std::move(b)))>);
  REQUIRE(based::max(std::move(a), std::move(b)) == 4);
}

// NOLINTEND move-const-arg

TEST_CASE("max-stability", "[based/algorithm/max]")
{
  using type_t = std::pair<int, int>;

  static const auto cmp = [](const type_t& x, const type_t& y)
  { return x.first < y.first; };

  const type_t a = {3, 4};
  const type_t b = {3, 5};

  REQUIRE(based::max(a, b, cmp).second == 5);
  REQUIRE(based::max(b, a, cmp).second == 4);
}
