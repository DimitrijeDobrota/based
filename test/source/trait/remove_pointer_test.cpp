#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove_pointer.hpp"

using based::SameAs;

TEST_CASE("remove_pointer", "[trait/remove_pointer]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int*>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int**>, int*>);
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int* const>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int* volatile>, int>);
  STATIC_REQUIRE(SameAs<based::trait::RemovePointer<int* const volatile>, int>);
  // clang-format on
  // NOLINTEND(*array*)
}
