#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/remove_reference.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

using based::trait::IsSame;

TEST_CASE("remove_reference", "[trait/remove_reference]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int&&>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const int>, const int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const int&>, const int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const int[2]>, const int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const int(&)[2]>, const int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<int(int)>, int(int)>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int>,volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int&>, volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int&&>, volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int(&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<volatile int(&&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const volatile int>, const volatile int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const volatile int&>, volatile const int>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const volatile int[2]>, const volatile int[2]>);
  STATIC_REQUIRE(IsSame<based::trait::RemoveReference<const volatile int(&)[2]>, volatile const int[2]>);
  // NOLINTEND(*array*)
  // clang-format on
}
