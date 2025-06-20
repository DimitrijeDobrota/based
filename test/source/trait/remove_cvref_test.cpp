#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove/cvref.hpp"

using based::SameAs;

TEST_CASE("remove_cvref", "[trait/remove_cvref]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const int&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int&&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<volatile int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvrefT<const volatile int(&)[2]>, int[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
