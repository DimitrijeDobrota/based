#include "based/functional/curry.hpp"

#include <catch2/catch_test_macros.hpp>

// NOLINTBEGIN(*cognitive-complexity*, *magic*)

namespace
{

auto free_func(int a, double b, int c, double d)
{
  return static_cast<int>(a + b + c + d);
}

}  // namespace

TEST_CASE("free function", "[functional/curry]")
{
  const based::Curried curried = free_func;

  REQUIRE(curried(1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(1)(2.0, 3, 4.0) == 10);
  REQUIRE(curried(1, 2.0)(3, 4.0) == 10);
  REQUIRE(curried(1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(1, 2.0, 3, 4.0) == 10);
}

TEST_CASE("lambda", "[functional/curry]")
{
  const based::Curried curried = [](int a, double b, int c, double d)
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
  struct Test
  {
    [[nodiscard]] auto func(int a, double b, int c, double d) const
    {
      return static_cast<int>(m_x + a + b + c + d);
    }

    int m_x = 0;
  };

  const based::Curried curried = &Test::func;
  Test                 tmp;

  REQUIRE(curried(std::ref(tmp))(1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1)(2.0)(3, 4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1)(2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1, 2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1, 2.0)(3, 4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp))(1, 2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1)(2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1)(2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1, 2.0)(3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1, 2.0, 3)(4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1, 2.0, 3, 4.0) == 10);
  REQUIRE(curried(std::ref(tmp), 1, 2.0, 3, 4.0) == 10);
}

// NOLINTEND(*cognitive-complexity*, *magic*)
