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

TEST_CASE("find_if(empty)", "[algorithm/find_if]")
{
  const std::array<int, 0> arr = {};
  const auto* it =
      based::find_if(std::begin(arr), std::end(arr), predicate {0});

  REQUIRE(it == std::end(arr));
}

TEST_CASE("find_if(one) = found", "[algorithm/find_if]")
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

TEST_CASE("find_if(two) = found", "[algorithm/find_if]")
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

TEST_CASE("find_if(multiple) = found", "[algorithm/find_if]")
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

TEST_CASE("find_if_not(empty)", "[algorithm/find_if_not]")
{
  const std::array<int, 0> arr = {};
  const auto* it =
      based::find_if_not(std::begin(arr), std::end(arr), predicate {0});

  REQUIRE(it == std::end(arr));
}

TEST_CASE("find_if_not(one) = found", "[algorithm/find_if_not]")
{
  const std::array arr = {0};

  SECTION("found")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {1});

    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find_if_not(two) = found", "[algorithm/find_if_not]")
{
  const std::array arr = {0, 1};

  SECTION("found 1")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("found 2")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 1);
  }
}

TEST_CASE("find_if_not(multiple) = found", "[algorithm/find_if_not]")
{
  const std::array arr = {0, 0, 0, 0};

  SECTION("found")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {1});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 0);
  }

  SECTION("not found")
  {
    const auto* itr =
        based::find_if_not(std::begin(arr), std::end(arr), predicate {0});
    const auto idx = std::distance(std::cbegin(arr), itr);
    REQUIRE(idx == 4);
  }
}

TEST_CASE("all(empty)", "[algorithm/all]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::all(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("all(homogeneous)", "[algorithm/all]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("all(non homogenous)", "[algorithm/all]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("none(empty)", "[algorithm/none]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("none(homogeneous)", "[algorithm/none]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("none(non homogeneous)", "[algorithm/none]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::none(std::begin(arr), std::end(arr), predicate {0}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::none(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("not_all(empty)", "[algorithm/not_all]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("not_all(homogeneous)", "[algorithm/not_all]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::not_all(std::begin(arr), std::end(arr), predicate {1}));
}

TEST_CASE("not_all(non homogeneous)", "[algorithm/not_all]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {0}));
  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(based::not_all(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("some(empty)", "[algorithm/some]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {0}));
}

TEST_CASE("some(homogeneous)", "[algorithm/some]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {2}));
}

TEST_CASE("some(non homogeneous)", "[algorithm/some]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {1}));
  REQUIRE(based::some(std::begin(arr), std::end(arr), predicate {2}));
  REQUIRE(!based::some(std::begin(arr), std::end(arr), predicate {0}));
}
