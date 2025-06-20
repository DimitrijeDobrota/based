#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove/cv.hpp"

using based::SameAs;

TEST_CASE("remove_cv", "[trait/remove_cv]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveCvT<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
