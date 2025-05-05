#include <array>

#include "based/algorithms/search/some.hpp"

#include <catch2/catch_test_macros.hpp>

struct predicate
{
  int goal;

  explicit predicate(int init)
      : goal(init)
  {
  }

  auto operator()(int n) const { return n == goal; }
};

TEST_CASE("some(empty)", "[algorithm/some]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("some(homogeneous)", "[algorithm/some]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("some(non homogeneous)", "[algorithm/some]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("some_n(empty)", "[algorithm/some_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("some_n(homogeneous)", "[algorithm/some_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("some_n(non homogeneous)", "[algorithm/some_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {0}));
}
