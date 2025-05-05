#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"
#include "based/type_traits/remove/cvref.hpp"

using based::SameAs;

TEST_CASE("remove_cvref", "[type_traits/remove_cvref]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int&&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int(&)[2]>, int[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
