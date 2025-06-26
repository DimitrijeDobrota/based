#include "based/container/array.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"

using namespace based::literals;  // NOLINT(*namespace*)

template class based::Array<based::U16, based::U8, 0_u8>;
template class based::Array<based::U16, based::U8, 1_u8>;

TEST_CASE("Array", "[container/Array]")
{
  REQUIRE(true);
}
