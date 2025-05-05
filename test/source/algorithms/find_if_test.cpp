#include <array>

#include "based/algorithms/search/find_if.hpp"

#include <catch2/catch_test_macros.hpp>

struct predicate
{
  int goal;

  explicit predicate(int init)
      : goal(init)
  {
  }

  auto operator()(int n) const { return n == goal; }
};

TEST_CASE("find_if(empty)", "[algorithm/find_if]")
{
  const std::array<int, 0> arr = {};
  const auto* itr =
      based::find_if(std::begin(arr), std::end(arr), predicate {0});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE("find_if(one)", "[algorithm/find_if]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find_if(two)", "[algorithm/find_if]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("found 2")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }

  SECTION("not found")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {2});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 2);
  }
}

TEST_CASE("find_if(multiple)", "[algorithm/find_if]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr =
        based::find_if(std::begin(arr), std::end(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 4);
  }
}

TEST_CASE("find_if_n(empty)", "[algorithm/find_if_n]")
{
  const std::array<int, 0> arr = {};
  const auto [itr, left] =
      based::find_if_n(std::begin(arr), std::size(arr), predicate {0});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE("find_if_n(one)", "[algorithm/find_if_n]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_if_n(two)", "[algorithm/find_if_n]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("found 2")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {2});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 2);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_if_n(multiple)", "[algorithm/find_if_n]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_if_n(std::begin(arr), std::size(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 4);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_if_unguarded(one)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {0});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}

TEST_CASE("find_if_unguarded(two)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0, 1};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {1});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 1);
}

TEST_CASE("find_if_unguarded(multiple)", "[algorithm/find_if_unguarded]")
{
  const std::array arr = {0, 0, 0, 0};

  const auto* itr = based::find_if_unguarded(std::begin(arr), predicate {0});
  const auto idx = std::distance(std::cbegin(arr), itr);
  REQUIRE(idx == 0);
}
