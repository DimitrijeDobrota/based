#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

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

TEST_CASE("upper_bound(empty)", "[algorithm/lower_bound]")
{
  std::array<int, 0> arr = {};

  const auto* itr =
      based::upper_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("upper_bound(one equal)", "[algorithm/lower_bound]")
{
  std::array arr = {4};

  const auto* itr =
      based::upper_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("upper_bound(one nonequal)", "[algorithm/lower_bound]")
{
  std::array arr = {1};

  const auto* itr =
      based::upper_bound(std::begin(arr), std::end(arr), 4, std::less<int> {});
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("upper_bound(sequence)", "[algorithm/lower_bound]")
{
  std::array arr = {0, 1, 2, 3, 3, 4};

  const auto* itr =
      based::upper_bound(std::begin(arr), std::end(arr), 3, std::less<int> {});
  REQUIRE(itr == std::next(std::begin(arr), 5));
}
