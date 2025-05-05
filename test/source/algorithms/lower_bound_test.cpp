#include <array>

#include "based/algorithms/bsearch/lower_bound.hpp"

#include <catch2/catch_test_macros.hpp>

struct equal
{
  auto operator()(int a) const { return a == goal; }

  int goal;
};

TEST_CASE("lower_bound(empty)", "[algorithm/lower_bound]")
{
  std::array<int, 0> arr = {};

  const auto* itr =
      based::lower_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("lower_bound(one equal)", "[algorithm/lower_bound]")
{
  std::array arr = {4};

  const auto* itr =
      based::lower_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::begin(arr));
}

TEST_CASE("lower_bound(one nonequal)", "[algorithm/lower_bound]")
{
  std::array arr = {1};

  const auto* itr =
      based::lower_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("lower_bound(sequence)", "[algorithm/lower_bound]")
{
  std::array arr = {0, 1, 2, 3, 3, 4};

  const auto* itr =
      based::lower_bound(std::begin(arr), std::end(arr), 3, std::less<int> {});
  REQUIRE(itr == std::next(std::begin(arr), 3));
}
