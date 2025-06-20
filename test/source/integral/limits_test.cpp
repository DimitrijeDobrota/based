#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/integral/types.hpp"

using based::limits;

TEST_CASE("unsigned", "[integral/literals]")
{
  STATIC_REQUIRE(limits<based::U8>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::U16>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::U32>::min.value == 0ULL);
  STATIC_REQUIRE(limits<based::U64>::min.value == 0ULL);

  STATIC_REQUIRE(limits<based::U8>::max.value == 255ULL);
  STATIC_REQUIRE(limits<based::U16>::max.value == 65535ULL);
  STATIC_REQUIRE(limits<based::U32>::max.value == 4294967295ULL);
  STATIC_REQUIRE(limits<based::U64>::max.value == 18446744073709551615ULL);
}

TEST_CASE("signed", "[integral/literals]")
{
  STATIC_REQUIRE(limits<based::I8>::min.value == -128LL);
  STATIC_REQUIRE(limits<based::I16>::min.value == -32768LL);
  STATIC_REQUIRE(limits<based::I32>::min.value == -2147483648LL);
  STATIC_REQUIRE(limits<based::I64>::min.value == -9223372036854775807LL - 1);

  STATIC_REQUIRE(limits<based::I8>::max.value == 127LL);
  STATIC_REQUIRE(limits<based::I16>::max.value == 32767LL);
  STATIC_REQUIRE(limits<based::I32>::max.value == 2147483647LL);
  STATIC_REQUIRE(limits<based::I64>::max.value == 9223372036854775807LL);
}
