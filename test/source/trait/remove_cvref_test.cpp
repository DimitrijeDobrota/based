#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove_cvref.hpp"

using based::SameAs;

TEST_CASE("remove_cvref", "[trait/remove_cvref]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const int&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int&&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<volatile int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCvref<const volatile int(&)[2]>, int[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
