#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/integral/types.hpp"

using based::limits;

TEST_CASE("unsigned", "[integral/literals]")
{
  STATIC_REQUIRE(limits<based::u8>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::u16>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::u32>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::u64>::min.value == 0ULL);

  STATIC_REQUIRE(limits<based::u8>::max.value == 255ULL);
  STATIC_REQUIRE(limits<based::u16>::max.value == 65535ULL);
  STATIC_REQUIRE(limits<based::u32>::max.value == 4294967295ULL);
  STATIC_REQUIRE(limits<based::u64>::max.value == 18446744073709551615ULL);
}

TEST_CASE("signed", "[integral/literals]")
{
  STATIC_REQUIRE(limits<based::i8>::min.value == -128LL);
  STATIC_REQUIRE(limits<based::i16>::min.value == -32768LL);
  STATIC_REQUIRE(limits<based::i32>::min.value == -2147483648LL);
  STATIC_REQUIRE(limits<based::i64>::min.value == -9223372036854775807LL - 1);

  STATIC_REQUIRE(limits<based::i8>::max.value == 127LL);
  STATIC_REQUIRE(limits<based::i16>::max.value == 32767LL);
  STATIC_REQUIRE(limits<based::i32>::max.value == 2147483647LL);
  STATIC_REQUIRE(limits<based::i64>::max.value == 9223372036854775807LL);
}
