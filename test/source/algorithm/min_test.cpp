#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/algorithm/min.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/utility/move.hpp"

// NOLINTBEGIN(*const-arg*,*const-correctness*,*after-move, *access-moved)

TEST_CASE("min(literal, literal) = left", "[algorithm/min]")
{
  using res_t = decltype(based::min(3, 4));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(3, 4) == 3);
}

TEST_CASE("min(literal, literal) = right", "[algorithm/min]")
{
  using res_t = decltype(based::min(4, 3));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(4, 3) == 3);
}

TEST_CASE("min(value, literal) = left", "[algorithm/min]")
{
  int a = 3;

  using res_t = decltype(based::min(a, 4));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(value, literal) = right", "[algorithm/min]")
{
  int a = 4;

  using res_t = decltype(based::min(a, 3));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, value) = left", "[algorithm/min]")
{
  int b = 4;

  using res_t = decltype(based::min(3, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, value) = right", "[algorithm/min]")
{
  int b = 3;

  using res_t = decltype(based::min(4, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(value, value) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, value) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, literal) = left", "[algorithm/min]")
{
  const int a = 3;

  using res_t = decltype(based::min(a, 4));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, 4) == 3);
}

TEST_CASE("min(const value, literal) = right", "[algorithm/min]")
{
  const int a = 4;

  using res_t = decltype(based::min(a, 3));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, 3) == 3);
}

TEST_CASE("min(literal, const value) = left", "[algorithm/min]")
{
  const int b = 4;

  using res_t = decltype(based::min(3, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(3, b) == 3);
}

TEST_CASE("min(literal, const value) = right", "[algorithm/min]")
{
  const int b = 3;

  using res_t = decltype(based::min(4, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(4, b) == 3);
}

TEST_CASE("min(const value, const value) = left", "[algorithm/min]")
{
  const int a = 3;
  const int b = 4;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, const value) = right", "[algorithm/min]")
{
  const int a = 4;
  const int b = 3;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = left", "[algorithm/min]")
{
  int a = 3;
  const int b = 4;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(value, const value) = right", "[algorithm/min]")
{
  int a = 4;
  const int b = 3;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = left", "[algorithm/min]")
{
  const int a = 3;
  int b = 4;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(const value, value) = right", "[algorithm/min]")
{
  const int a = 4;
  int b = 3;

  using res_t = decltype(based::min(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::min(a, b) == 3);
}

TEST_CASE("min(move, literal) = left", "[algorithm/min]")
{
  int a = 3;

  using res_t = decltype(based::min(based::move(a), 4));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(based::move(a), 4) == 3);
}

TEST_CASE("min(move, literal) = right", "[algorithm/min]")
{
  int a = 4;

  using res_t = decltype(based::min(based::move(a), 3));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(based::move(a), 3) == 3);
}

TEST_CASE("min(move, value) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::min(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(based::move(a), b) == 3);
}

TEST_CASE("min(move, value) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::min(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(based::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = left", "[algorithm/min]")
{
  int a = 3;
  const int b = 4;

  using res_t = decltype(based::min(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(based::move(a), b) == 3);
}

TEST_CASE("min(move, const value) = right", "[algorithm/min]")
{
  int a = 4;
  const int b = 3;

  using res_t = decltype(based::min(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(based::move(a), b) == 3);
}

TEST_CASE("min(literal, move) = left", "[algorithm/min]")
{
  int b = 4;

  using res_t = decltype(based::min(3, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(3, based::move(b)) == 3);
}

TEST_CASE("min(literal, move) = right", "[algorithm/min]")
{
  int b = 3;

  using res_t = decltype(based::min(4, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(4, based::move(b)) == 3);
}

TEST_CASE("min(value, move) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::min(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, based::move(b)) == 3);
}

TEST_CASE("min(value, move) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::min(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, based::move(b)) == 3);
}

TEST_CASE("min(const value, move) = left", "[algorithm/min]")
{
  const int a = 3;
  int b = 4;

  using res_t = decltype(based::min(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, based::move(b)) == 3);
}

TEST_CASE("min(const value, move) = right", "[algorithm/min]")
{
  const int a = 4;
  int b = 3;

  using res_t = decltype(based::min(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::min(a, based::move(b)) == 3);
}

TEST_CASE("min(move, move) = left", "[algorithm/min]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::min(based::move(a), based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(based::move(a), based::move(b)) == 3);
}

TEST_CASE("min(move, move) = right", "[algorithm/min]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::min(based::move(a), based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::min(based::move(a), based::move(b)) == 3);
}

// NOLINTEND(*const-arg*,*const-correctness*,*after-move, *access-moved)

TEST_CASE("min-stability", "[algorithm/min]")
{
  using type_t = std::pair<int, int>;

  static const auto cmp = [](const type_t& x, const type_t& y)
  {
    return x.first < y.first;
  };

  const type_t a = {3, 4};
  const type_t b = {3, 5};

  REQUIRE(based::min(a, b, cmp).second == 4);
  REQUIRE(based::min(b, a, cmp).second == 5);
}
