#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove/const.hpp"

using based::SameAs;

TEST_CASE("remove_const", "[trait/remove/remove_const]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const int>, int>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int>, volatile int>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const volatile int>, volatile int>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::RemoveConstT<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
  // NOLINTEND(*array*)
}
