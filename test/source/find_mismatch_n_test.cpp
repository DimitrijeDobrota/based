#include <array>

#include <catch2/catch_test_macros.hpp>

#include "based/algorithm.hpp"

struct equal
{
  auto operator()(int a, int b) const { return a == b; }
};

TEST_CASE("find_mismatch_n(empty)", "[algorithm/find_mismatch_n]")
{
  std::array<int, 0> arr0 = {};
  std::array<int, 0> arr1 = {};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch_n(empty, nonempty)", "[algorithm/find_mismatch_n]")
{
  std::array<int, 0> arr0 = {};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::begin(arr1));
}

TEST_CASE("find_mismatch_n(nonempty, empty)", "[algorithm/find_mismatch_n]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array<int, 0> arr1 = {};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::begin(arr0));
  REQUIRE(n0 == std::size(arr0));

  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch_n(equal)", "[algorithm/find_mismatch_n]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch_n(equal, longer)", "[algorithm/find_mismatch_n]")
{
  std::array arr0 = {0, 1, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::next(std::begin(arr1), std::size(arr0)));
}

TEST_CASE("find_mismatch_n(longer, equal)", "[algorithm/find_mismatch_n]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), std::size(arr1)));
  REQUIRE(n0 == 2);

  REQUIRE(itr1 == std::end(arr1));
}

TEST_CASE("find_mismatch_n(mismatch)", "[algorithm/find_mismatch_n]")
{
  std::array arr0 = {0, 1, 4, 3, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1] = based::find_mismatch_n(std::begin(arr0),
                                                       std::size(arr0),
                                                       std::begin(arr1),
                                                       std::end(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), 2));
  REQUIRE(n0 == 3);

  REQUIRE(itr1 == std::next(std::begin(arr1), 2));
}

TEST_CASE("find_mismatch_m(empty)", "[algorithm/find_mismatch_m]")
{
  std::array<int, 0> arr0 = {};
  std::array<int, 0> arr1 = {};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_m(empty, nonempty)", "[algorithm/find_mismatch_m]")
{
  std::array<int, 0> arr0 = {};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));

  REQUIRE(itr1 == std::begin(arr1));
  REQUIRE(n1 == std::size(arr1));
}

TEST_CASE("find_mismatch_m(nonempty, empty)", "[algorithm/find_mismatch_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array<int, 0> arr1 = {};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::begin(arr0));

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_m(equal)", "[algorithm/find_mismatch_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_m(equal, longer)", "[algorithm/find_mismatch_m]")
{
  std::array arr0 = {0, 1, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::end(arr0));

  REQUIRE(itr1 == std::next(std::begin(arr1), std::size(arr0)));
  REQUIRE(n1 == 2);
}

TEST_CASE("find_mismatch_m(longer, equal)", "[algorithm/find_mismatch_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), std::size(arr1)));

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_m(mismatch)", "[algorithm/find_mismatch_m]")
{
  std::array arr0 = {0, 1, 4, 3, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, itr1, n1] = based::find_mismatch_m(std::begin(arr0),
                                                       std::end(arr0),
                                                       std::begin(arr1),
                                                       std::size(arr1),
                                                       equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), 2));

  REQUIRE(itr1 == std::next(std::begin(arr1), 2));
  REQUIRE(n1 == 3);
}

TEST_CASE("find_mismatch_n_m(empty)", "[algorithm/find_mismatch_n_m]")
{
  std::array<int, 0> arr0 = {};
  std::array<int, 0> arr1 = {};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_n_m(empty, nonempty)", "[algorithm/find_mismatch_n_m]")
{
  std::array<int, 0> arr0 = {};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::begin(arr1));
  REQUIRE(n1 == std::size(arr1));
}

TEST_CASE("find_mismatch_n_m(nonempty, empty)", "[algorithm/find_mismatch_n_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array<int, 0> arr1 = {};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::begin(arr0));
  REQUIRE(n0 == std::size(arr0));

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_n_m(equal)", "[algorithm/find_mismatch_n_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_n_m(equal, longer)", "[algorithm/find_mismatch_n_m]")
{
  std::array arr0 = {0, 1, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::end(arr0));
  REQUIRE(n0 == 0);

  REQUIRE(itr1 == std::next(std::begin(arr1), std::size(arr0)));
  REQUIRE(n1 == 2);
}

TEST_CASE("find_mismatch_n_m(longer, equal)", "[algorithm/find_mismatch_n_m]")
{
  std::array arr0 = {0, 1, 2, 3, 4};
  std::array arr1 = {0, 1, 2};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), std::size(arr1)));
  REQUIRE(n0 == 2);

  REQUIRE(itr1 == std::end(arr1));
  REQUIRE(n1 == 0);
}

TEST_CASE("find_mismatch_n_m(mismatch)", "[algorithm/find_mismatch_n_m]")
{
  std::array arr0 = {0, 1, 4, 3, 2};
  std::array arr1 = {0, 1, 2, 3, 4};

  const auto [itr0, n0, itr1, n1] = based::find_mismatch_n_m(std::begin(arr0),
                                                             std::size(arr0),
                                                             std::begin(arr1),
                                                             std::size(arr1),
                                                             equal {});

  REQUIRE(itr0 == std::next(std::begin(arr0), 2));
  REQUIRE(n0 == 3);

  REQUIRE(itr1 == std::next(std::begin(arr1), 2));
  REQUIRE(n1 == 3);
}
