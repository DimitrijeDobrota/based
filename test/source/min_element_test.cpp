#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("min_element(empty)", "[based/algorithm/min_element]")
{
  std::array<int, 0> arr = {};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("min_element(1)", "[based/algorithm/min_element]")
{
  std::array arr = {0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(2) = first", "[based/algorithm/min_element]")
{
  std::array arr = {0, 1};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(2) = second", "[based/algorithm/min_element]")
{
  std::array arr = {1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("min_element(2) = stable", "[based/algorithm/min_element]")
{
  std::array arr = {0, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = first", "[based/algorithm/min_element]")
{
  std::array arr = {0, 1, 2};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = second", "[based/algorithm/min_element]")
{
  std::array arr = {1, 0, 2};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("min_element(3) = third", "[based/algorithm/min_element]")
{
  std::array arr = {2, 1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("min_element(3) = stable(1, 2)", "[based/algorithm/min_element]")
{
  std::array arr = {0, 0, 1};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = stable(1, 3)", "[based/algorithm/min_element]")
{
  std::array arr = {0, 1, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("min_element(3) = stable(2, 3)", "[based/algorithm/min_element]")
{
  std::array arr = {1, 0, 0};
  const auto* itr = based::min_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}
