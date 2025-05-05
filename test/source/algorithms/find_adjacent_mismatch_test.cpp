#include <array>

#include "based/algorithms/search/find_adjacent_mismatch.hpp"

#include <catch2/catch_test_macros.hpp>

struct equal
{
  auto operator()(int a, int b) const { return a == b; }
};

TEST_CASE("find_adjacent_mismatch(empty)", "[algorithm/find_adjacent_mismatch]")
{
  std::array<int, 0> arr = {};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE("find_adjacent_mismatch(one)", "[algorithm/find_adjacent_mismatch]")
{
  std::array arr = {0};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch(two equal)", "[algorithm/find_adjacent_mismatch]"
)
{
  std::array arr = {0, 0};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch(two nonequal)", "[algorithm/find_adjacent_mismatch]"
)
{
  std::array arr = {0, 1};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::next(std::begin(arr), 1));
}

TEST_CASE("find_adjacent_mismatch(equal)", "[algorithm/find_adjacent_mismatch]")
{
  std::array arr = {0, 0, 0, 0, 0, 0};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch(nonequal)", "[algorithm/find_adjacent_mismatch]"
)
{
  std::array arr = {0, 0, 0, 0, 1, 1, 1, 1};

  const auto* itr =
      based::find_adjacent_mismatch(std::begin(arr), std::end(arr), equal {});

  REQUIRE(itr == std::next(std::begin(arr), 4));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(empty)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array<int, 0> arr = {};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(one)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array arr = {0};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(two equal)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array arr = {0, 0};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(two nonequal)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array arr = {0, 1};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::next(std::begin(arr), 1));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(equal)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array arr = {0, 0, 0, 0, 0, 0};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::end(arr));
}

TEST_CASE(
    "find_adjacent_mismatch_forward(nonequal)",
    "[algorithm/find_adjacent_mismatch_forward]"
)
{
  std::array arr = {0, 0, 0, 0, 1, 1, 1, 1};

  const auto* itr = based::find_adjacent_mismatch_forward(
      std::begin(arr), std::end(arr), equal {}
  );

  REQUIRE(itr == std::next(std::begin(arr), 4));
}
