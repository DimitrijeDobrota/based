#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("min_element(empty)", "[algorithm/min_element]")
{
  const std::array<int, 0> arr = {};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("min_element(1)", "[algorithm/min_element]")
{
  const std::array arr = {0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(2) = first", "[algorithm/min_element]")
{
  const std::array arr = {0, 1};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(2) = second", "[algorithm/min_element]")
{
  const std::array arr = {1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("min_element(2) = stable", "[algorithm/min_element]")
{
  const std::array arr = {0, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = first", "[algorithm/min_element]")
{
  const std::array arr = {0, 1, 2};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = second", "[algorithm/min_element]")
{
  const std::array arr = {1, 0, 2};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("min_element(3) = third", "[algorithm/min_element]")
{
  const std::array arr = {2, 1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("min_element(3) = stable(1, 2)", "[algorithm/min_element]")
{
  const std::array arr = {0, 0, 1};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = stable(1, 3)", "[algorithm/min_element]")
{
  const std::array arr = {0, 1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = stable(2, 3)", "[algorithm/min_element]")
{
  const std::array arr = {1, 0, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}
