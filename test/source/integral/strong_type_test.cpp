#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/integral/strong.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"

struct T1 : based::StrongType<based::U8, T1>
{
  using StrongType::StrongType;
  using StrongType::operator=;
};

struct T2 : based::StrongType<based::U8, T2>
{
  using StrongType::StrongType;
  using StrongType::operator=;
};

// NOLINTBEGIN(*needed*,*internal-linkage*)
auto compare(T1, T1) -> bool;
auto compare(T2, T2) -> bool;

auto add(T1, T1) -> T1;
auto add(T1, T2) -> T1;
auto add(T2, T1) -> T2;
// NOLINTEND(*needed*,*internal-linkage*)

TEST_CASE("StrongType", "[integral/StrongType]")
{
  STATIC_REQUIRE(based::Addable<T1, T1>);
  STATIC_REQUIRE(!based::Addable<T2, T2>);
  STATIC_REQUIRE(based::Addable<T1, T2>);
  STATIC_REQUIRE(based::Addable<T2, T1>);

  using namespace based::literals;  // NOLINT(*namespace*)
  REQUIRE(T1 {10_u8} + T1 {20_u8} == T1 {30_u8});
  REQUIRE(T1 {10_u8} + T2 {20_u8} == T1 {30_u8});
  REQUIRE(T2 {10_u8} + T1 {20_u8} == T2 {30_u8});
}
