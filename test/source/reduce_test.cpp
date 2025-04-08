#include <array>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct op
{
  auto operator()(const auto& a, const auto& b) { return a + b; }
};

struct fun
{
  auto operator()(based::Iterator auto it) { return *it; }
};

TEST_CASE("reduce(empty)", "[algorithm/reduce]")
{
  const std::array<int, 0> arr = {};

  const auto count =
      based::reduce(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 0);
}

TEST_CASE("reduce(sequence)", "[algorithm/reduce]")
{
  const std::array arr = {0, 1, 2, 3, 4, 5};

  const auto count =
      based::reduce(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 15);
}

TEST_CASE("reduce_nonzero(empty)", "[algorithm/reduce_nonzero]")
{
  const std::array<int, 0> arr = {};

  const auto count =
      based::reduce_nonzero(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 0);
}

TEST_CASE("reduce_nonzero(sequence)", "[algorithm/reduce_nonzero]")
{
  const std::array arr = {0, 1, 2, 3, 4, 5};

  const auto count =
      based::reduce_nonzero(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 15);
}
