#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"
#include "based/type_traits.hpp"

struct predicate
{
  int goal;

  explicit predicate(int init)
      : goal(init)
  {
  }

  auto operator()(int n) const { return n == goal; }
};

TEST_CASE("count_if_n return type", "[algorithm/count_if_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(
      based::SameAs<based::iter_dist_t<decltype(arr)::iterator>,
                    decltype(based::count_if_n(
                                 std::begin(arr), std::size(arr), predicate {0})
                                 .second)>);

  REQUIRE(based::SameAs<std::uint8_t,
                        decltype(based::count_if_n(std::begin(arr),
                                                   std::size(arr),
                                                   predicate {0},
                                                   std::uint8_t {0})
                                     .second)>);
}

TEST_CASE("count_if_n(empty)", "[algorithm/count_if_n]")
{
  const std::array<int, 0> arr = {};

  const auto [itr, count] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {0});

  REQUIRE(count == 0);
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("count_if_n(homogeneous)", "[algorithm/count_if_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto [itr0, count0] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {0});

  const auto [itr1, count1] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {1});

  REQUIRE(count0 == 0);
  REQUIRE(itr0 == std::end(arr));

  REQUIRE(count1 == 6);
  REQUIRE(itr1 == std::end(arr));
}

TEST_CASE("count_if_n(non homogeneous)", "[algorithm/count_if_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto [itr0, count0] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {0});

  const auto [itr1, count1] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {1});

  const auto [itr2, count2] =
      based::count_if_n(std::begin(arr), std::size(arr), predicate {2});

  REQUIRE(count0 == 0);
  REQUIRE(itr0 == std::end(arr));

  REQUIRE(count1 == 4);
  REQUIRE(itr1 == std::end(arr));

  REQUIRE(count2 == 2);
  REQUIRE(itr2 == std::end(arr));
}

TEST_CASE("count_if_not_n return type", "[algorithm/count_if_not_n]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(
      based::SameAs<based::iter_dist_t<decltype(arr)::iterator>,
                    decltype(based::count_if_not_n(
                                 std::begin(arr), std::size(arr), predicate {0})
                                 .second)>);

  REQUIRE(based::SameAs<std::uint8_t,
                        decltype(based::count_if_not_n(std::begin(arr),
                                                       std::size(arr),
                                                       predicate {0},
                                                       std::uint8_t {0})
                                     .second)>);
}

TEST_CASE("count_if_not_n(empty)", "[algorithm/count_if_not_n]")
{
  const std::array<int, 0> arr = {};

  const auto [itr, count] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {0});

  REQUIRE(count == 0);
  REQUIRE(itr == std::end(arr));
}

TEST_CASE("count_if_not_n(homogeneous)", "[algorithm/count_if_not_n]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto [itr0, count0] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {0});

  const auto [itr1, count1] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {1});

  REQUIRE(count0 == 6);
  REQUIRE(itr0 == std::end(arr));

  REQUIRE(count1 == 0);
  REQUIRE(itr1 == std::end(arr));
}

TEST_CASE("count_if_not_n(non homogeneous)", "[algorithm/count_if_not_n]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto [itr0, count0] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {0});

  const auto [itr1, count1] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {1});

  const auto [itr2, count2] =
      based::count_if_not_n(std::begin(arr), std::size(arr), predicate {2});

  REQUIRE(count0 == 6);
  REQUIRE(itr0 == std::end(arr));

  REQUIRE(count1 == 2);
  REQUIRE(itr1 == std::end(arr));

  REQUIRE(count2 == 4);
  REQUIRE(itr2 == std::end(arr));
}
