#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/types/strong.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/types/literals.hpp"

struct t1 : based::strong_type<based::u8, t1>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

struct t2 : based::strong_type<based::u8, t2>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

// NOLINTBEGIN(*needed*,*internal-linkage*)
auto compare(t1, t1) -> bool;
auto compare(t2, t2) -> bool;

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

  using namespace based::literals;  // NOLINT(*namespace*)
  REQUIRE(t1 {10_u8} + t1 {20_u8} == t1 {30_u8});
  REQUIRE(t1 {10_u8} + t2 {20_u8} == t1 {30_u8});
  REQUIRE(t2 {10_u8} + t1 {20_u8} == t2 {30_u8});
}
