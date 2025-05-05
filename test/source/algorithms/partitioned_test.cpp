#include <array>

#include "based/algorithms/sort/partitioned.hpp"

#include <catch2/catch_test_macros.hpp>

struct equal
{
  auto operator()(int a) const { return a == goal; }

  int goal;
};

TEST_CASE("partitioned(empty)", "[algorithm/partitioned]")
{
  std::array<int, 0> arr = {};

  REQUIRE(based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}

TEST_CASE("partitioned(one equal)", "[algorithm/partitioned]")
{
  std::array arr = {4};

  REQUIRE(based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}

TEST_CASE("partitioned(one nonequal)", "[algorithm/partitioned]")
{
  std::array arr = {1};

  REQUIRE(based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}

TEST_CASE("partitioned(partitioned)", "[algorithm/partitioned]")
{
  std::array arr = {0, 1, 2, 3, 4, 4, 4, 4};

  REQUIRE(based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}

TEST_CASE("partitioned(nonpartitioned equal)", "[algorithm/partitioned]")
{
  std::array arr = {4, 0, 1, 2, 3, 4, 4, 4};
  REQUIRE(!based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}

TEST_CASE("partitioned(nonpartitioned nonequal)", "[algorithm/partitioned]")
{
  std::array arr = {4, 0, 1, 2, 3, 4, 4, 4, 0};

  REQUIRE(!based::partitioned(std::begin(arr), std::end(arr), equal {4}));
}
