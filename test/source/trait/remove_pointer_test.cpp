#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove/pointer.hpp"

using based::SameAs;

TEST_CASE("remove_pointer", "[trait/remove_pointer]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int>, int>);
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int*>, int>);
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int**>, int*>);
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int* const>, int>);
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int* volatile>, int>);
  STATIC_REQUIRE(SameAs<based::RemovePointerT<int* const volatile>, int>);
  // clang-format on
  // NOLINTEND(*array*)
}
