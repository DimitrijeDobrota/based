#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/types/literals.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"

using namespace based::literals;  // NOLINT(*namespace*)

using based::SameAs;

TEST_CASE("unsigned", "[types/literals]")
{
  STATIC_REQUIRE(SameAs<decltype(0_u), based::u8>);
  STATIC_REQUIRE(SameAs<decltype(255_u), based::u8>);
  STATIC_REQUIRE(SameAs<decltype(256_u), based::u16>);
  STATIC_REQUIRE(SameAs<decltype(65535_u), based::u16>);
  STATIC_REQUIRE(SameAs<decltype(65536_u), based::u32>);
  STATIC_REQUIRE(SameAs<decltype(4294967295_u), based::u32>);
  STATIC_REQUIRE(SameAs<decltype(4294967296_u), based::u64>);
  STATIC_REQUIRE(SameAs<decltype(18446744073709551615_u), based::u64>);
}

TEST_CASE("signed", "[types/literals]")
{
  STATIC_REQUIRE(SameAs<decltype(0_i), based::i8>);
  STATIC_REQUIRE(SameAs<decltype(127_i), based::i8>);
  STATIC_REQUIRE(SameAs<decltype(128_i), based::i16>);
  STATIC_REQUIRE(SameAs<decltype(32767_i), based::i16>);
  STATIC_REQUIRE(SameAs<decltype(2147483647_i), based::i32>);
  STATIC_REQUIRE(SameAs<decltype(2147483648_i), based::i64>);
  STATIC_REQUIRE(SameAs<decltype(9223372036854775807_i), based::i64>);

  STATIC_REQUIRE(SameAs<decltype(-127_i), based::i8>);
  STATIC_REQUIRE(SameAs<decltype(-128_i), based::i16>);
  STATIC_REQUIRE(SameAs<decltype(-32767_i), based::i16>);
  STATIC_REQUIRE(SameAs<decltype(-2147483647_i), based::i32>);
  STATIC_REQUIRE(SameAs<decltype(-2147483648_i), based::i64>);
  STATIC_REQUIRE(SameAs<decltype(-9223372036854775807_i), based::i64>);
}
