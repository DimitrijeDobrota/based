#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove_reference.hpp"

using based::SameAs;

TEST_CASE("remove_reference", "[trait/remove_reference]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const int>, const int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const int&>, const int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const int[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const int(&)[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int>,volatile int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int&>, volatile int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int&&>, volatile int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int(&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<volatile int(&&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const volatile int>, const volatile int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const volatile int&>, volatile const int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const volatile int[2]>, const volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveReference<const volatile int(&)[2]>, volatile const int[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
