#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/remove_const.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

using based::trait::IsSame;

TEST_CASE("remove_const", "[trait/remove/remove_const]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int&>, int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int&&>, int&&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const int&>, const int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<int(int)>, int(int)>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int>, volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int&>, volatile int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const volatile int>, volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveConst<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
