#include <array>

#include "based/algorithms/sort/partition_point.hpp"

#include <catch2/catch_test_macros.hpp>

struct equal
{
  auto operator()(int a) const { return a == goal; }

  int goal;
};

TEST_CASE("partition_point(empty)", "[algorithm/partition_point]")
{
  std::array<int, 0> arr = {};

  const auto* itr =
      based::partition_point(std::begin(arr), std::end(arr), equal {4});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("partition_point(one equal)", "[algorithm/partition_point]")
{
  std::array arr = {4};

  const auto* itr =
      based::partition_point(std::begin(arr), std::end(arr), equal {4});
  REQUIRE(itr == std::begin(arr));
}

TEST_CASE("partition_point(one nonequal)", "[algorithm/partition_point]")
{
  std::array arr = {1};

  const auto* itr =
      based::partition_point(std::begin(arr), std::end(arr), equal {4});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("partition_point(sequence)", "[algorithm/partition_point]")
{
  std::array arr = {0, 1, 2, 3, 4, 4, 4, 4};

  const auto* itr =
      based::partition_point(std::begin(arr), std::end(arr), equal {4});
  REQUIRE(itr == std::next(std::begin(arr), 4));
}
