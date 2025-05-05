#include <array>

#include "based/algorithms/minmax/max_element.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("max_element(empty)", "[algorithm/max_element]")
{
  const std::array<int, 0> arr = {};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("max_element(1)", "[algorithm/max_element]")
{
  const std::array arr = {0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(2) = first", "[algorithm/max_element]")
{
  const std::array arr = {1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(2) = second", "[algorithm/max_element]")
{
  const std::array arr = {0, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(2) = stable", "[algorithm/max_element]")
{
  const std::array arr = {0, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = first", "[algorithm/max_element]")
{
  const std::array arr = {2, 1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(3) = second", "[algorithm/max_element]")
{
  const std::array arr = {1, 2, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = third", "[algorithm/max_element]")
{
  const std::array arr = {0, 1, 2};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("max_element(3) = stable(1, 2)", "[algorithm/max_element]")
{
  const std::array arr = {1, 1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = stable(1, 3)", "[algorithm/max_element]")
{
  const std::array arr = {1, 0, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("max_element(3) = stable(2, 3)", "[algorithm/max_element]")
{
  const std::array arr = {0, 1, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}
