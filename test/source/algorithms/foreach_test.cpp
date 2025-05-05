#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithms/batch/for_each.hpp"

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

TEST_CASE("for_each_n(empty)", "[algorithm/for_each_n]")
{
  const std::array<int, 0> arr = {};
  const auto [f, itr] =
      based::for_each_n(std::begin(arr), std::size(arr), functor {});

  REQUIRE(f.sum == 0);
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("for_each_n(one)", "[algorithm/for_each_n]")
{
  const std::array arr = {1};
  const auto [f, itr] =
      based::for_each_n(std::begin(arr), std::size(arr), functor {});

  REQUIRE(f.sum == 1);
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("for_each_n(two)", "[algorithm/for_each_n]")
{
  const std::array arr = {1, 2};
  const auto [f, itr] =
      based::for_each_n(std::begin(arr), std::size(arr), functor {});

  REQUIRE(f.sum == 3);
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("for_each_n(three)", "[algorithm/for_each_n]")
{
  const std::array arr = {1, 2, 3};
  const auto [f, itr] =
      based::for_each_n(std::begin(arr), std::size(arr), functor {});

  REQUIRE(f.sum == 6);
  REQUIRE(itr == std::end(arr));
}
