#include <array>

#include "based/algorithms/search/find.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("find(empty)", "[algorithm/find]")
{
  const std::array<int, 0> arr = {};
  const auto* itr = based::find(std::begin(arr), std::end(arr), 0);

  REQUIRE(itr == std::end(arr));
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

TEST_CASE("find_n(empty)", "[algorithm/find_n]")
{
  const std::array<int, 0> arr = {};
  const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 0);
  const auto idx = std::distance(std::cbegin(arr), itr);

  REQUIRE(idx == 0);
  REQUIRE(idx + left == std::size(arr));
}

TEST_CASE("find_n(one)", "[algorithm/find_n]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }
  SECTION("not found")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_n(two)", "[algorithm/find_n]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("found 2")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 2);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 2);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_n(multiple)", "[algorithm/find_n]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 4);
    REQUIRE(idx + left == std::size(arr));
  }
}
