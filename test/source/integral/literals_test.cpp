#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/integral/literals.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/castable.hpp"

using namespace based::literals;  // NOLINT(*namespace*)

using based::CastableTo;

TEST_CASE("unsigned", "[integral/literals]")
{
  STATIC_REQUIRE(CastableTo<decltype(0_u), based::U8>);
  STATIC_REQUIRE(CastableTo<decltype(255_u), based::U8>);
  STATIC_REQUIRE(CastableTo<decltype(256_u), based::U16>);
  STATIC_REQUIRE(CastableTo<decltype(65535_u), based::U16>);
  STATIC_REQUIRE(CastableTo<decltype(65536_u), based::U32>);
  STATIC_REQUIRE(CastableTo<decltype(4294967295_u), based::U32>);
  STATIC_REQUIRE(CastableTo<decltype(4294967296_u), based::U64>);
  STATIC_REQUIRE(CastableTo<decltype(18446744073709551615_u), based::U64>);
}

TEST_CASE("signed", "[integral/literals]")
{
  STATIC_REQUIRE(CastableTo<decltype(0_i), based::I8>);
  STATIC_REQUIRE(CastableTo<decltype(127_i), based::I8>);
  STATIC_REQUIRE(CastableTo<decltype(128_i), based::I16>);
  STATIC_REQUIRE(CastableTo<decltype(32767_i), based::I16>);
  STATIC_REQUIRE(CastableTo<decltype(2147483647_i), based::I32>);
  STATIC_REQUIRE(CastableTo<decltype(2147483648_i), based::I64>);
  STATIC_REQUIRE(CastableTo<decltype(9223372036854775807_i), based::I64>);

  STATIC_REQUIRE(CastableTo<decltype(-127_i), based::I8>);
  STATIC_REQUIRE(CastableTo<decltype(-128_i), based::I16>);
  STATIC_REQUIRE(CastableTo<decltype(-32767_i), based::I16>);
  STATIC_REQUIRE(CastableTo<decltype(-2147483647_i), based::I32>);
  STATIC_REQUIRE(CastableTo<decltype(-2147483648_i), based::I64>);
  STATIC_REQUIRE(CastableTo<decltype(-9223372036854775807_i), based::I64>);
}
