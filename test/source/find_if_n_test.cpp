#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct predicate
{
  int goal;

  explicit predicate(int init)
      : goal(init)
  {
  }

  auto operator()(int n) const { return n == goal; }
};

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

TEST_CASE("find_if_not_n(empty)", "[algorithm/find_if_not_n]")
{
  const std::array<int, 0> arr = {};
  const auto [itr, left] =
      based::find_if_not_n(std::begin(arr), std::size(arr), predicate {0});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE("find_if_not_n(one)", "[algorithm/find_if_not_n]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {1});

    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_if_not_n(two)", "[algorithm/find_if_not_n]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("found 2")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 1);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("find_if_not_n(multiple)", "[algorithm/find_if_not_n]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 0);
    REQUIRE(idx + left == std::size(arr));
  }

  SECTION("not found")
  {
    const auto [itr, left] =
        based::find_if_not_n(std::begin(arr), std::size(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);

    REQUIRE(idx == 4);
    REQUIRE(idx + left == std::size(arr));
  }
}

TEST_CASE("all_n(empty)", "[algorithm/all_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::all_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("all_n(homogeneous)", "[algorithm/all_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("all_n(non homogenous)", "[algorithm/all_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::all_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("none_n(empty)", "[algorithm/none_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("none_n(homogeneous)", "[algorithm/none_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {1}));
}

TEST_CASE("none_n(non homogeneous)", "[algorithm/none_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::none_n(std::begin(arr), std::size(arr), predicate {0}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::none_n(std::begin(arr), std::size(arr), predicate {1}));
}

TEST_CASE("not_all_n(empty)", "[algorithm/not_all_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("not_all_n(homogeneous)", "[algorithm/not_all_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::not_all_n(std::begin(arr), std::size(arr), predicate {1}));
}

TEST_CASE("not_all_n(non homogeneous)", "[algorithm/not_all_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {0}));
  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(based::not_all_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("some_n(empty)", "[algorithm/some_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {0}));
}

TEST_CASE("some_n(homogeneous)", "[algorithm/some_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {2}));
}

TEST_CASE("some_n(non homogeneous)", "[algorithm/some_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {1}));
  REQUIRE(based::some_n(std::begin(arr), std::size(arr), predicate {2}));
  REQUIRE(!based::some_n(std::begin(arr), std::size(arr), predicate {0}));
}
