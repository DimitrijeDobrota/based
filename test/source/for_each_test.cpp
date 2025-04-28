#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct functor
{
  int operator()(int n) { return sum += n; }

  int sum = 0;
};

TEST_CASE("for_each(empty)", "[algorithm/for_each]")
{
  const std::array<int, 0> arr = {};
  const auto func = based::for_each(std::begin(arr), std::end(arr), functor {});

  REQUIRE(func.sum == 0);
}

TEST_CASE("for_each(one)", "[algorithm/for_each]")
{
  const std::array arr = {1};
  const auto func = based::for_each(std::begin(arr), std::end(arr), functor {});

  REQUIRE(func.sum == 1);
}

TEST_CASE("for_each(two)", "[algorithm/for_each]")
{
  const std::array arr = {1, 2};
  const auto func = based::for_each(std::begin(arr), std::end(arr), functor {});

  REQUIRE(func.sum == 3);
}

TEST_CASE("for_each(three)", "[algorithm/for_each]")
{
  const std::array arr = {1, 2, 3};
  const auto func = based::for_each(std::begin(arr), std::end(arr), functor {});

  REQUIRE(func.sum == 6);
}
