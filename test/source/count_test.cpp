#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"
#include "based/type_traits.hpp"

TEST_CASE("count return type", "[algorithm/count]")
{
  const std::array<int, 0> arr = {};

  SECTION("auto counter")
  {
    using res_t = decltype(based::count(std::begin(arr), std::end(arr), 0));
    REQUIRE(based::SameAs<based::iter_dist_t<decltype(arr)::iterator>, res_t>);
  }

  SECTION("explicit counter")
  {
    using res_t = decltype(based::count(
        std::begin(arr), std::end(arr), 0, std::uint8_t {0}
    ));
    REQUIRE(based::SameAs<std::uint8_t, res_t>);
  }
}

TEST_CASE("count(empty)", "[algorithm/count]")
{
  const std::array<int, 0> arr = {};

  const auto count = based::count(std::begin(arr), std::end(arr), 0);

  REQUIRE(count == 0);
}

TEST_CASE("count(homogeneous)", "[algorithm/count]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto count0 = based::count(std::begin(arr), std::end(arr), 0);
  const auto count1 = based::count(std::begin(arr), std::end(arr), 1);
  REQUIRE(count0 == 0);
  REQUIRE(count1 == 6);
}

TEST_CASE("count(non homogeneous)", "[algorithm/count]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto count0 = based::count(std::begin(arr), std::end(arr), 0);
  const auto count1 = based::count(std::begin(arr), std::end(arr), 1);
  const auto count2 = based::count(std::begin(arr), std::end(arr), 2);

  REQUIRE(count0 == 0);
  REQUIRE(count1 == 4);
  REQUIRE(count2 == 2);
}

TEST_CASE("count_not return type", "[algorithm/count_not]")
{
  const std::array<int, 0> arr = {};

  SECTION("auto counter")
  {
    using res_t = decltype(based::count_not(std::begin(arr), std::end(arr), 0));
    REQUIRE(based::SameAs<based::iter_dist_t<decltype(arr)::iterator>, res_t>);
  }

  SECTION("explicit counter")
  {
    using res_t = decltype(based::count_not(
        std::begin(arr), std::end(arr), 0, std::uint8_t {0}
    ));
    REQUIRE(based::SameAs<std::uint8_t, res_t>);
  }
}

TEST_CASE("count_not(empty)", "[algorithm/count_not]")
{
  const std::array<int, 0> arr = {};

  const auto count_not = based::count_not(std::begin(arr), std::end(arr), 0);

  REQUIRE(count_not == 0);
}

TEST_CASE("count_not(homogeneous)", "[algorithm/count_not]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto count0 = based::count_not(std::begin(arr), std::end(arr), 0);
  const auto count1 = based::count_not(std::begin(arr), std::end(arr), 1);

  REQUIRE(count0 == 6);
  REQUIRE(count1 == 0);
}

TEST_CASE("count_not(non homogeneous)", "[algorithm/count_not]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto count0 = based::count_not(std::begin(arr), std::end(arr), 0);
  const auto count1 = based::count_not(std::begin(arr), std::end(arr), 1);
  const auto count2 = based::count_not(std::begin(arr), std::end(arr), 2);

  REQUIRE(count0 == 6);
  REQUIRE(count1 == 2);
  REQUIRE(count2 == 4);
}
