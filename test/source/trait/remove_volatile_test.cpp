#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/remove_volatile.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

using based::trait::IsSame;

TEST_CASE("remove_volatile", "[trait/remove/remove_volatile]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int&>, int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int&&>, int&&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const int>, const int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const int&>, const int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const int[2]>, const int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<int(int)>, int(int)>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int&>, volatile int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const volatile int>, const int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const volatile int[2]>, const int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveVolatile<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
