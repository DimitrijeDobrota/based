#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/integral/literals.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/castable.hpp"

using namespace based::literals;  // NOLINT(*namespace*)

using based::CastableTo;

TEST_CASE("unsigned", "[integral/literals]")
{
  STATIC_REQUIRE(CastableTo<decltype(0_u), based::u8>);
  STATIC_REQUIRE(CastableTo<decltype(255_u), based::u8>);
  STATIC_REQUIRE(CastableTo<decltype(256_u), based::u16>);
  STATIC_REQUIRE(CastableTo<decltype(65535_u), based::u16>);
  STATIC_REQUIRE(CastableTo<decltype(65536_u), based::u32>);
  STATIC_REQUIRE(CastableTo<decltype(4294967295_u), based::u32>);
  STATIC_REQUIRE(CastableTo<decltype(4294967296_u), based::u64>);
  STATIC_REQUIRE(CastableTo<decltype(18446744073709551615_u), based::u64>);
}

TEST_CASE("signed", "[integral/literals]")
{
  STATIC_REQUIRE(CastableTo<decltype(0_i), based::i8>);
  STATIC_REQUIRE(CastableTo<decltype(127_i), based::i8>);
  STATIC_REQUIRE(CastableTo<decltype(128_i), based::i16>);
  STATIC_REQUIRE(CastableTo<decltype(32767_i), based::i16>);
  STATIC_REQUIRE(CastableTo<decltype(2147483647_i), based::i32>);
  STATIC_REQUIRE(CastableTo<decltype(2147483648_i), based::i64>);
  STATIC_REQUIRE(CastableTo<decltype(9223372036854775807_i), based::i64>);

  STATIC_REQUIRE(CastableTo<decltype(-127_i), based::i8>);
  STATIC_REQUIRE(CastableTo<decltype(-128_i), based::i16>);
  STATIC_REQUIRE(CastableTo<decltype(-32767_i), based::i16>);
  STATIC_REQUIRE(CastableTo<decltype(-2147483647_i), based::i32>);
  STATIC_REQUIRE(CastableTo<decltype(-2147483648_i), based::i64>);
  STATIC_REQUIRE(CastableTo<decltype(-9223372036854775807_i), based::i64>);
}
