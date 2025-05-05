#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <array>

#include "based/algorithms/search/count_if.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"

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

  SECTION("auto counter")
  {
    using res_t =
        decltype(based::count_if(std::begin(arr), std::end(arr), predicate {0})
        );

    STATIC_REQUIRE(based::SameAs<
                   based::iter_dist_t<decltype(arr)::iterator>,
                   res_t>);
  }

  SECTION("explicit counter")
  {
    using res_t = decltype(based::count_if(
        std::begin(arr), std::end(arr), predicate {0}, based::u8 {0}
    ));

    STATIC_REQUIRE(based::SameAs<based::u8, res_t>);
  }
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

TEST_CASE("count_if_n return type", "[algorithm/count_if_n]")
{
  const std::array<int, 0> arr = {};

  SECTION("auto counter")
  {
    using res_t = decltype(based::count_if_n(
                               std::begin(arr), std::size(arr), predicate {0}
    )
                               .second);
    STATIC_REQUIRE(based::SameAs<
                   based::iter_dist_t<decltype(arr)::iterator>,
                   res_t>);
  }

  SECTION("explicit counter")
  {
    using res_t = decltype(based::count_if_n(
                               std::begin(arr),
                               std::size(arr),
                               predicate {0},
                               based::u8 {0}
    )
                               .second);
    STATIC_REQUIRE(based::SameAs<based::u8, res_t>);
  }
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
