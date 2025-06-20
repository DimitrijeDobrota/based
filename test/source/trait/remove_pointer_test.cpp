#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/remove_pointer.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

using based::trait::IsSame;

TEST_CASE("remove_pointer", "[trait/remove_pointer]")
{
  // clang-format off
  // NOLINTBEGIN(*array*)
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int*>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int**>, int*>);
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int* const>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int* volatile>, int>);
  STATIC_REQUIRE(IsSame<based::trait::RemovePointer<int* const volatile>, int>);
  // NOLINTEND(*array*)
  // clang-format on
}
