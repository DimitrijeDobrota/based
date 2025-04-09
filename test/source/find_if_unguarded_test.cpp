#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct predicate
{
  int goal;

  explicit predicate(int init)
      : goal(init)
  {
  }

  auto operator()(int n) const { return n == goal; }
};

TEST_CASE("find_if_unguarded(one)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {0});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("find_if_unguarded(two)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0, 1};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {1});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("find_if_unguarded(multiple)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0, 0, 0, 0};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {0});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("find_if_not_unguarded(one)", "[algorithm/find_if_not_unguarded]")
{
  const std::array arr = {0};

  const auto* itr =
      based::find_if_not_unguarded(std::begin(arr), predicate {1});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("find_if_not_unguarded(two)", "[algorithm/find_if_not_unguarded]")
{
  const std::array arr = {0, 1};

  const auto* itr =
      based::find_if_not_unguarded(std::begin(arr), predicate {0});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("find_if_not_unguarded(multiple)",
          "[algorithm/find_if_not_unguarded]")
{
  const std::array arr = {1, 1, 0, 1};

  const auto* itr =
      based::find_if_not_unguarded(std::begin(arr), predicate {1});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}
