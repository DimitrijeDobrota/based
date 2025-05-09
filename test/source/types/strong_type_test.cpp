// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/types/strong.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/types/types.hpp"

struct t1 : based::strong_type<based::u8, t1>
{
};

struct t2 : based::strong_type<based::u8, t2>
{
};

// NOLINTBEGIN(*needed*,*internal-linkage*)
auto equal(t1, t1) -> bool;
auto equal(t2, t2) -> bool;

auto add(t1, t1) -> t1;
auto add(t1, t2) -> t1;
auto add(t2, t1) -> t2;
// NOLINTEND(*needed*,*internal-linkage*)

TEST_CASE("strong_type", "[types/strong_type]")
{
  STATIC_REQUIRE(based::addable<t1, t1>);
  STATIC_REQUIRE(!based::addable<t2, t2>);
  STATIC_REQUIRE(based::addable<t1, t2>);
  STATIC_REQUIRE(based::addable<t2, t1>);

  REQUIRE(t1 {10} + t1 {20} == t1 {30});
  REQUIRE(t1 {10} + t2 {20} == t1 {30});
  REQUIRE(t2 {10} + t1 {20} == t2 {30});
}
