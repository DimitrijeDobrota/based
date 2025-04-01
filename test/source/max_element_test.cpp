#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("max_element(empty)", "[based/algorithm/max_element]")
{
  std::array<int, 0> arr = {};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("max_element(1)", "[based/algorithm/max_element]")
{
  std::array arr = {0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(2) = first", "[based/algorithm/max_element]")
{
  std::array arr = {1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(2) = second", "[based/algorithm/max_element]")
{
  std::array arr = {0, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(2) = stable", "[based/algorithm/max_element]")
{
  std::array arr = {0, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = first", "[based/algorithm/max_element]")
{
  std::array arr = {2, 1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("max_element(3) = second", "[based/algorithm/max_element]")
{
  std::array arr = {1, 2, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = third", "[based/algorithm/max_element]")
{
  std::array arr = {0, 1, 2};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("max_element(3) = stable(1, 2)", "[based/algorithm/max_element]")
{
  std::array arr = {1, 1, 0};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("max_element(3) = stable(1, 3)", "[based/algorithm/max_element]")
{
  std::array arr = {1, 0, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}

TEST_CASE("max_element(3) = stable(2, 3)", "[based/algorithm/max_element]")
{
  std::array arr = {0, 1, 1};
  const auto* itr = based::max_element(std::begin(arr), std::end(arr));
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 2);
}
