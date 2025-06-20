#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/remove_cvref.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

using based::trait::IsSame;

TEST_CASE("remove_cvref", "[trait/remove_cvref]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int&&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const int&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const int(&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<int(int)>, int(int)>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int&&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int(&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<volatile int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const volatile int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const volatile int&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveCvref<const volatile int(&)[2]>, int[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
