#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("minmax_element(empty)", "[algorithm/minmax_element]")
{
  std::array<int, 0> arr = {};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  REQUIRE(min == std::end(arr));
  REQUIRE(max == std::end(arr));
}

TEST_CASE("minmax_element(1)", "[algorithm/minmax_element]")
{
  std::array arr = {0};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 0);
  REQUIRE(maxi == 0);
}

TEST_CASE("minmax_element(increasing even)", "[algorithm/minmax_element]")
{
  std::array arr = {0, 1, 2, 3};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 0);
  REQUIRE(maxi == std::size(arr) - 1);
}

TEST_CASE("minmax_element(increasing odd)", "[algorithm/minmax_element]")
{
  std::array arr = {0, 1, 2, 3, 4};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 0);
  REQUIRE(maxi == std::size(arr) - 1);
}

TEST_CASE("minmax_element(decreasing even)", "[algorithm/minmax_element]")
{
  std::array arr = {3, 2, 1, 0};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == std::size(arr) - 1);
  REQUIRE(maxi == 0);
}

TEST_CASE("minmax_element(decreasing odd)", "[algorithm/minmax_element]")
{
  std::array arr = {4, 3, 2, 1, 0};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == std::size(arr) - 1);
  REQUIRE(maxi == 0);
}

TEST_CASE("minmax_element(stable even)", "[algorithm/minmax_element]")
{
  std::array arr = {3, 0, 0, 3};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 1);
  REQUIRE(maxi == std::size(arr) - 1);
}

TEST_CASE("minmax_element(stable odd)", "[algorithm/minmax_element]")
{
  std::array arr = {3, 0, 3, 3, 0};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 1);
  REQUIRE(maxi == std::size(arr) - 2);
}

TEST_CASE("minmax_element(stable increasing)", "[algorithm/minmax_element]")
{
  std::array arr = {0, 0, 1, 2, 3, 4, 4};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == 0);
  REQUIRE(maxi == std::size(arr) - 1);
}

TEST_CASE("minmax_element(stable decreasing)", "[algorithm/minmax_element]")
{
  std::array arr = {4, 4, 3, 2, 1, 0, 0};
  const auto [min, max] = based::minmax_element(std::begin(arr), std::end(arr));
  const auto mini = std::distance(std::begin(arr), min);
  const auto maxi = std::distance(std::begin(arr), max);
  REQUIRE(mini == std::size(arr) - 2);
  REQUIRE(maxi == 1);
}
