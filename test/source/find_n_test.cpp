#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

TEST_CASE("find_n(empty)", "[algorithm/find_n]")
{
  const std::array<int, 0> arr = {};
  const auto [itr, left] = based::find_n(std::begin(arr), std::size(arr), 0);
  const auto idx = std::distance(std::cbegin(arr), itr);

  REQUIRE(idx == 0);
  REQUIRE(idx + left == std::size(arr));
}

TEST_CASE("find_n(one) = found", "[algorithm/find_n]")
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

TEST_CASE("find_n(two) = found", "[algorithm/find_n]")
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

TEST_CASE("find_n(multiple) = found", "[algorithm/find_n]")
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

TEST_CASE("find_not_n(empty)", "[algorithm/find_not_n]")
{
  const std::array<int, 0> arr = {};

  const auto [itr, left] =
      based::find_not_n(std::begin(arr), std::size(arr), 0);
  const auto idx = std::distance(std::cbegin(arr), itr);

  REQUIRE(idx == 0);
  REQUIRE(idx + left == std::size(arr));
}

TEST_CASE("find_not_n(one) = found", "[algorithm/find_not_n]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_not_n(two) = found", "[algorithm/find_not_n]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("found 2")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_not_n(multiple) = found", "[algorithm/find_not_n]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 1);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_not_n(std::begin(arr), std::size(arr), 0);
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 4);
    REQUIRE(idx + left == std::size(arr));
  }
}
