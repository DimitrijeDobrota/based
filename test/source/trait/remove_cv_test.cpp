#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove_cv.hpp"

using based::SameAs;

TEST_CASE("remove_cv", "[trait/remove_cv]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::trait::RemoveCv<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
