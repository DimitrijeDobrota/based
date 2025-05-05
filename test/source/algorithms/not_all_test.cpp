#include <array>

#include "based/algorithms/search/not_all.hpp"

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

TEST_CASE("not_all(empty)", "[algorithm/not_all]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("not_all(homogeneous)", "[algorithm/not_all]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::not_all(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("not_all(non homogeneous)", "[algorithm/not_all]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {0}));
  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("not_all_n(empty)", "[algorithm/not_all_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("not_all_n(homogeneous)", "[algorithm/not_all_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::not_all_n(std::begin(arr), std::size(arr), predicate {1}));
}

TEST_CASE("not_all_n(non homogeneous)", "[algorithm/not_all_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {0}));
  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {2}));
}
