#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct equal
{
  auto operator()(int a, int b) const { return a == b; }
};

TEST_CASE("find_mismatch(empty)", "[algorithm/find_mismatch]")
{
  std::array<int, 0> arr0 = {};
  std::array<int, 0> arr1 = {};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch(empty, nonempty)", "[algorithm/find_mismatch]")
{
  std::array<int, 0> arr0 = {};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(itr1 == std::begin(arr1));
}

TEST_CASE("find_mismatch(nonempty, empty)", "[algorithm/find_mismatch]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array<int, 0> arr1 = {};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::begin(arr0));
  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch(equal)", "[algorithm/find_mismatch]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch(equal, longer)", "[algorithm/find_mismatch]")
{
  std::array arr0 = {0, 1, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(itr1 == std::next(std::begin(arr1), std::size(arr0)));
}

TEST_CASE("find_mismatch(longer, equal)", "[algorithm/find_mismatch]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), std::size(arr1)));
  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch(mismatch)", "[algorithm/find_mismatch]")
{
  std::array arr0 = {0, 1, 4, 3, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1] = based::find_mismatch(std::begin(arr0),
                                                 std::end(arr0),
                                                 std::begin(arr1),
                                                 std::end(arr1),
                                                 equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), 2));
  REQUIRE(itr1 == std::next(std::begin(arr1), 2));
}
