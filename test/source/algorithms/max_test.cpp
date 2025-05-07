#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/algorithms/max.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"
#include "based/utility/move.hpp"

// NOLINTBEGIN(*const-arg*,*const-correctness*,*after-move, *access-moved)

TEST_CASE("max(literal, literal) = right", "[algorithm/max]")
{
  using res_t = decltype(based::max(3, 4));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(3, 4) == 4);
}

TEST_CASE("max(literal, literal) = left", "[algorithm/max]")
{
  using res_t = decltype(based::max(4, 3));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(4, 3) == 4);
}

TEST_CASE("max(value, literal) = right", "[algorithm/max]")
{
  int a = 3;

  using res_t = decltype(based::max(a, 4));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, 4) == 4);
}

TEST_CASE("max(value, literal) = left", "[algorithm/max]")
{
  int a = 4;

  using res_t = decltype(based::max(a, 3));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, 3) == 4);
}

TEST_CASE("max(literal, value) = right", "[algorithm/max]")
{
  int b = 4;

  using res_t = decltype(based::max(3, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(3, b) == 4);
}

TEST_CASE("max(literal, value) = left", "[algorithm/max]")
{
  int b = 3;

  using res_t = decltype(based::max(4, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(4, b) == 4);
}

TEST_CASE("max(value, value) = right", "[algorithm/max]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, value) = left", "[algorithm/max]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, literal) = right", "[algorithm/max]")
{
  const int a = 3;

  using res_t = decltype(based::max(a, 4));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, 4) == 4);
}

TEST_CASE("max(const value, literal) = left", "[algorithm/max]")
{
  const int a = 4;

  using res_t = decltype(based::max(a, 3));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, 3) == 4);
}

TEST_CASE("max(literal, const value) = right", "[algorithm/max]")
{
  const int b = 4;

  using res_t = decltype(based::max(3, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(3, b) == 4);
}

TEST_CASE("max(literal, const value) = left", "[algorithm/max]")
{
  const int b = 3;

  using res_t = decltype(based::max(4, b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(4, b) == 4);
}

TEST_CASE("max(const value, const value) = right", "[algorithm/max]")
{
  const int a = 3;
  const int b = 4;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, const value) = left", "[algorithm/max]")
{
  const int a = 4;
  const int b = 3;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, const value) = right", "[algorithm/max]")
{
  int a = 3;
  const int b = 4;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(value, const value) = left", "[algorithm/max]")
{
  int a = 4;
  const int b = 3;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, value) = right", "[algorithm/max]")
{
  const int a = 3;
  int b = 4;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(const value, value) = left", "[algorithm/max]")
{
  const int a = 4;
  int b = 3;

  using res_t = decltype(based::max(a, b));

  STATIC_REQUIRE(based::SameAs<const int&, res_t>);
  REQUIRE(based::max(a, b) == 4);
}

TEST_CASE("max(move, literal) = right", "[algorithm/max]")
{
  int a = 3;

  using res_t = decltype(based::max(based::move(a), 4));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(based::move(a), 4) == 4);
}

TEST_CASE("max(move, literal) = left", "[algorithm/max]")
{
  int a = 4;

  using res_t = decltype(based::max(based::move(a), 3));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(based::move(a), 3) == 4);
}

TEST_CASE("max(move, value) = right", "[algorithm/max]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::max(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(based::move(a), b) == 4);
}

TEST_CASE("max(move, value) = left", "[algorithm/max]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::max(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(based::move(a), b) == 4);
}

TEST_CASE("max(move, const value) = right", "[algorithm/max]")
{
  int a = 3;
  const int b = 4;

  using res_t = decltype(based::max(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(based::move(a), b) == 4);
}

TEST_CASE("max(move, const value) = left", "[algorithm/max]")
{
  int a = 4;
  const int b = 3;

  using res_t = decltype(based::max(based::move(a), b));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(based::move(a), b) == 4);
}

TEST_CASE("max(literal, move) = right", "[algorithm/max]")
{
  int b = 4;

  using res_t = decltype(based::max(3, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(3, based::move(b)) == 4);
}

TEST_CASE("max(literal, move) = left", "[algorithm/max]")
{
  int b = 3;

  using res_t = decltype(based::max(4, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(4, based::move(b)) == 4);
}

TEST_CASE("max(value, move) = right", "[algorithm/max]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::max(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, based::move(b)) == 4);
}

TEST_CASE("max(value, move) = left", "[algorithm/max]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::max(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, based::move(b)) == 4);
}

TEST_CASE("max(const value, move) = right", "[algorithm/max]")
{
  const int a = 3;
  int b = 4;

  using res_t = decltype(based::max(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, based::move(b)) == 4);
}

TEST_CASE("max(const value, move) = left", "[algorithm/max]")
{
  const int a = 4;
  int b = 3;

  using res_t = decltype(based::max(a, based::move(b)));

  STATIC_REQUIRE(based::SameAs<int, res_t>);
  REQUIRE(based::max(a, based::move(b)) == 4);
}

TEST_CASE("max(move, move) = right", "[algorithm/max]")
{
  int a = 3;
  int b = 4;

  using res_t = decltype(based::max(based::move(a), based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(based::move(a), based::move(b)) == 4);
}

TEST_CASE("max(move, move) = left", "[algorithm/max]")
{
  int a = 4;
  int b = 3;

  using res_t = decltype(based::max(based::move(a), based::move(b)));

  STATIC_REQUIRE(based::SameAs<int&&, res_t>);
  REQUIRE(based::max(based::move(a), based::move(b)) == 4);
}

// NOLINTEND(*const-arg*,*const-correctness*,*after-move, *access-moved)

TEST_CASE("max-stability", "[algorithm/max]")
{
  using type_t = std::pair<int, int>;

  static const auto cmp = [](const type_t& x, const type_t& y)
  {
    return x.first < y.first;
  };

  const type_t a = {3, 4};
  const type_t b = {3, 5};

  REQUIRE(based::max(a, b, cmp).second == 5);
  REQUIRE(based::max(b, a, cmp).second == 4);
}
