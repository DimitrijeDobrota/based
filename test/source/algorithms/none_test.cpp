#include <array>

#include "based/algorithms/search/none.hpp"

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

TEST_CASE("none(empty)", "[algorithm/none]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("none(homogeneous)", "[algorithm/none]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("none(non homogeneous)", "[algorithm/none]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {0}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("none_n(empty)", "[algorithm/none_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("none_n(homogeneous)", "[algorithm/none_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {1}));
}

TEST_CASE("none_n(non homogeneous)", "[algorithm/none_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {0}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {1}));
}
