#include <array>
#include <vector>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithms/numeric/accumulate.hpp"

struct op
{
  auto operator()(const auto& lhs, const auto& rhs) { return lhs + rhs; }
};

struct fun
{
  auto operator()(based::Iterator auto itr) { return *itr; }
};

TEST_CASE("accumulate_nonempty(sequence)", "[algorithm/accumulate_nonempty]")
{
  const std::array arr = {0, 1, 2, 3, 4, 5};

  const auto count = based::accumulate_nonempty(
      std::cbegin(arr), std::cend(arr), op {}, fun {}
  );

  REQUIRE(count == 15);
}

TEST_CASE("accumulate(empty)", "[algorithm/accumulate]")
{
  const std::array<int, 0> arr = {};

  const auto count =
      based::accumulate(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 0);
}

TEST_CASE("accumulate(sequence)", "[algorithm/accumulate]")
{
  const std::array arr = {0, 1, 2, 3, 4, 5};

  const auto count =
      based::accumulate(std::cbegin(arr), std::cend(arr), op {}, fun {}, 0);

  REQUIRE(count == 15);
}

TEST_CASE("accumulate_nonzero(empty)", "[algorithm/accumulate_nonzero]")
{
  const std::array<int, 0> arr = {};

  const auto count = based::accumulate_nonzero(
      std::cbegin(arr), std::cend(arr), op {}, fun {}, 0
  );

  REQUIRE(count == 0);
}

TEST_CASE("accumulate_nonzero(sequence)", "[algorithm/accumulate_nonzero]")
{
  const std::array arr = {0, 1, 2, 3, 4, 5};

  const auto count = based::accumulate_nonzero(
      std::cbegin(arr), std::cend(arr), op {}, fun {}, 0
  );

  REQUIRE(count == 15);
}
