#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("find(empty)", "[algorithm/find]")
{
  const std::array<int, 0> arr = {};
  const auto* it = based::find(std::begin(arr), std::end(arr), 0);

  REQUIRE(it == std::end(arr));
}

TEST_CASE("find(one) = found", "[algorithm/find]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find(two) = found", "[algorithm/find]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("found 2")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }

  SECTION("not found")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 2);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 2);
  }
}

TEST_CASE("find(multiple) = found", "[algorithm/find]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr = based::find(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 4);
  }
}

TEST_CASE("find_not(empty)", "[algorithm/find_not]")
{
  const std::array<int, 0> arr = {};
  const auto* it = based::find_not(std::begin(arr), std::end(arr), 0);

  REQUIRE(it == std::end(arr));
}

TEST_CASE("find_not(one) = found", "[algorithm/find_not]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find_not(two) = found", "[algorithm/find_not]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("found 2")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find_not(multiple) = found", "[algorithm/find_not]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr = based::find_not(std::begin(arr), std::end(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 4);
  }
}
