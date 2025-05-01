#include <catch2/catch_test_macros.hpp>

#include "based/functional.hpp"

// NOLINTBEGIN congnitive-complexity magic-number

auto free_func(int a, double b, int c, double d)
{
  return static_cast<int>(a + b + c + d);
};

TEST_CASE("free function", "[functional/curry]")
{
  const based::curried curried = free_func;

  REQUIRE(curried(1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(1)(2.0, 3, 4.0) == 10);
  REQUIRE(curried(1, 2.0)(3, 4.0) == 10);
  REQUIRE(curried(1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(1, 2.0, 3, 4.0) == 10);
}

TEST_CASE("lambda", "[functional/curry]")
{
  const based::curried curried = [](int a, double b, int c, double d)
  {
    return static_cast<int>(a + b + c + d);
  };

  REQUIRE(curried(1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(1)(2.0)(3, 4.0) == 10);
  REQUIRE(curried(1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(1)(2.0, 3, 4.0) == 10);
  REQUIRE(curried(1, 2.0)(3)(4.0) == 10);
  REQUIRE(curried(1, 2.0)(3, 4.0) == 10);
  REQUIRE(curried(1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(1, 2.0, 3, 4.0) == 10);
}

TEST_CASE("member function", "[functional/curry]")
{
  struct test
  {
    auto func(int a, double b, int c, double d) const
    {
      return static_cast<int>(a + b + c + d);
    }
  };

  const based::curried curried = &test::func;
  test t;

  REQUIRE(curried(std::ref(t))(1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(t))(1)(2.0)(3, 4.0) == 10);
  REQUIRE(curried(std::ref(t))(1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(t))(1)(2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(t))(1, 2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(t))(1, 2.0)(3, 4.0) == 10);
  REQUIRE(curried(std::ref(t))(1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(t))(1, 2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(t), 1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(t), 1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(t), 1, 2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(t), 1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(t), 1, 2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(t), 1, 2.0, 3, 4.0) == 10);
}

// NOLINTEND congnitive-complexity magic-number
