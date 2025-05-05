#include <array>

#include "based/algorithms/search/all.hpp"

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

TEST_CASE("all(empty)", "[algorithm/all]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::all(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("all(homogeneous)", "[algorithm/all]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("all(non homogenous)", "[algorithm/all]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("all_n(empty)", "[algorithm/all_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::all_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("all_n(homogeneous)", "[algorithm/all_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("all_n(non homogenous)", "[algorithm/all_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {2}));
}
