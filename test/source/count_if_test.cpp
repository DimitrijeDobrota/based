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

TEST_CASE("count_if return type", "[algorithm/count_if]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::SameAs<based::iter_dist_t<decltype(arr)::iterator>,
                        decltype(based::count_if(
                            std::begin(arr), std::end(arr), predicate {0}))>);

  REQUIRE(based::SameAs<std::uint8_t,
                        decltype(based::count_if(std::begin(arr),
                                                 std::end(arr),
                                                 predicate {0},
                                                 std::uint8_t {0}))>);
}

TEST_CASE("count_if(empty)", "[algorithm/count_if]")
{
  const std::array<int, 0> arr = {};

  const auto count =
      based::count_if(std::begin(arr), std::end(arr), predicate {0});

  REQUIRE(count == 0);
}

TEST_CASE("count_if(homogeneous)", "[algorithm/count_if]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto count0 =
      based::count_if(std::begin(arr), std::end(arr), predicate {0});
  const auto count1 =
      based::count_if(std::begin(arr), std::end(arr), predicate {1});

  REQUIRE(count0 == 0);
  REQUIRE(count1 == 6);
}

TEST_CASE("count_if(non homogeneous)", "[algorithm/count_if]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto count0 =
      based::count_if(std::begin(arr), std::end(arr), predicate {0});
  const auto count1 =
      based::count_if(std::begin(arr), std::end(arr), predicate {1});
  const auto count2 =
      based::count_if(std::begin(arr), std::end(arr), predicate {2});

  REQUIRE(count0 == 0);
  REQUIRE(count1 == 4);
  REQUIRE(count2 == 2);
}

TEST_CASE("count_if_not return type", "[algorithm/count_if_not]")
{
  const std::array<int, 0> arr = {};

  REQUIRE(based::SameAs<based::iter_dist_t<decltype(arr)::iterator>,
                        decltype(based::count_if_not(
                            std::begin(arr), std::end(arr), predicate {0}))>);

  REQUIRE(based::SameAs<std::uint8_t,
                        decltype(based::count_if_not(std::begin(arr),
                                                     std::end(arr),
                                                     predicate {0},
                                                     std::uint8_t {0}))>);
}

TEST_CASE("count_if_not(empty)", "[algorithm/count_if_not]")
{
  const std::array<int, 0> arr = {};

  const auto count =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {0});

  REQUIRE(count == 0);
}

TEST_CASE("count_if_not(homogeneous)", "[algorithm/count_if_not]")
{
  const std::array arr = {1, 1, 1, 1, 1, 1};

  const auto count0 =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {0});
  const auto count1 =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {1});

  REQUIRE(count0 == 6);
  REQUIRE(count1 == 0);
}

TEST_CASE("count_if_not(non homogeneous)", "[algorithm/count_if_not]")
{
  const std::array arr = {1, 2, 1, 1, 1, 2};

  const auto count0 =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {0});
  const auto count1 =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {1});
  const auto count2 =
      based::count_if_not(std::begin(arr), std::end(arr), predicate {2});

  REQUIRE(count0 == 6);
  REQUIRE(count1 == 2);
  REQUIRE(count2 == 4);
}
