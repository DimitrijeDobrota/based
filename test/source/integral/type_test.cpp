#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"
#include "based/integral/types.hpp"

using based::U16;
using based::U32;
using based::U64;
using based::U8;
using based::trait::IsSame;

TEST_CASE("U8", "[integral/types/U8]")
{
  // clang-format off
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs + rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs - rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs * rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs / rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs % rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs & rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs | rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs ^ rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs << rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs >> rhs } -> IsSame<U8>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs += rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs -= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs *= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs /= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs %= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs &= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs |= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs ^= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs <<= rhs } -> IsSame<U8&>; });
  STATIC_REQUIRE(requires(U8 lhs, U8 rhs) { { lhs >>= rhs } -> IsSame<U8&>; });

  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs + rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs - rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs * rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs / rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs << rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs >> rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs % rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs & rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs | rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U8 lhs, U16 rhs) { { lhs ^ rhs } -> IsSame<U16>; });

  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs + rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs - rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs * rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs / rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs % rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs << rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs >> rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs & rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs | rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs ^ rhs } -> IsSame<U32>; });

  STATIC_REQUIRE(requires(U8 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U8 lhs, U64 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  // clang-format on
}

TEST_CASE("U16", "[integral/types/U16]")
{
  // clang-format off
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs + rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs - rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs * rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs / rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs % rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs << rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs >> rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs & rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs | rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs ^ rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs += rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs -= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs *= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs /= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs %= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs &= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs |= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs ^= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs <<= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U8 rhs) { { lhs >>= rhs } -> IsSame<U16&>; });

  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs + rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs - rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs * rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs / rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs % rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs << rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs >> rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs & rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs | rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs ^ rhs } -> IsSame<U16>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs += rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs -= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs *= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs /= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs %= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs &= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs |= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs ^= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs <<= rhs } -> IsSame<U16&>; });
  STATIC_REQUIRE(requires(U16 lhs, U16 rhs) { { lhs >>= rhs } -> IsSame<U16&>; });

  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs + rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs - rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs * rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs / rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs % rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs << rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs >> rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs & rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs | rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs ^ rhs } -> IsSame<U32>; });

  STATIC_REQUIRE(requires(U16 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U16 lhs, U64 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  // clang-format on
}

TEST_CASE("U32", "[integral/types/U32]")
{
  // clang-format off
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs + rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs - rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs * rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs / rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs % rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs << rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs >> rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs & rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs | rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs ^ rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs += rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs -= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs *= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs /= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs %= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs &= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs |= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs ^= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs <<= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U8 rhs) { { lhs >>= rhs } -> IsSame<U32&>; });

  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs + rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs - rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs * rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs / rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs % rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs << rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs >> rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs & rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs | rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs ^ rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs += rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs -= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs *= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs /= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs %= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs &= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs |= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs ^= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs <<= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U16 rhs) { { lhs >>= rhs } -> IsSame<U32&>; });

  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs + rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs - rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs * rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs / rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs % rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs << rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs >> rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs & rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs | rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs ^ rhs } -> IsSame<U32>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs += rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs -= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs *= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs /= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs %= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs &= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs |= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs ^= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs <<= rhs } -> IsSame<U32&>; });
  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs >>= rhs } -> IsSame<U32&>; });

  STATIC_REQUIRE(requires(U32 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U32 lhs, U64 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  // clang-format on
}

TEST_CASE("U64", "[integral/types/U64]")
{
  // clang-format off
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs += rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs -= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs *= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs /= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs %= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs &= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs |= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs ^= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs <<= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U8 rhs) { { lhs >>= rhs } -> IsSame<U64&>; });

  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs += rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs -= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs *= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs /= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs %= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs &= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs |= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs ^= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs <<= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U16 rhs) { { lhs >>= rhs } -> IsSame<U64&>; });

  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs += rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs -= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs *= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs /= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs %= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs &= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs |= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs ^= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs <<= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs >>= rhs } -> IsSame<U64&>; });

  STATIC_REQUIRE(requires(U64 lhs, U32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs + rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs - rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs * rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs / rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs % rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs << rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs >> rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs & rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs | rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs ^ rhs } -> IsSame<U64>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs += rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs -= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs *= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs /= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs %= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs &= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs |= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs ^= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs <<= rhs } -> IsSame<U64&>; });
  STATIC_REQUIRE(requires(U64 lhs, U64 rhs) { { lhs >>= rhs } -> IsSame<U64&>; });
  // clang-format on
}

using based::I16;
using based::I32;
using based::I64;
using based::I8;

TEST_CASE("I8", "[integral/types/I8]")
{
  // clang-format off
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs + rhs } -> IsSame<I8>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs - rhs } -> IsSame<I8>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs * rhs } -> IsSame<I8>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs / rhs } -> IsSame<I8>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs % rhs } -> IsSame<I8>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs += rhs } -> IsSame<I8&>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs -= rhs } -> IsSame<I8&>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs *= rhs } -> IsSame<I8&>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs /= rhs } -> IsSame<I8&>; });
  STATIC_REQUIRE(requires(I8 lhs, I8 rhs) { { lhs %= rhs } -> IsSame<I8&>; });

  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs + rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs - rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs * rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs / rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I8 lhs, I16 rhs) { { lhs % rhs } -> IsSame<I16>; });

  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs + rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs - rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs * rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs / rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs % rhs } -> IsSame<I32>; });

  STATIC_REQUIRE(requires(I8 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I8 lhs, I64 rhs) { { lhs % rhs } -> IsSame<I64>; });
  // clang-format on
}

TEST_CASE("I16", "[integral/types/I16]")
{
  // clang-format off
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs + rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs - rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs * rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs / rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs % rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs += rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs -= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs *= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs /= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I8 rhs) { { lhs %= rhs } -> IsSame<I16&>; });

  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs + rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs - rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs * rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs / rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs % rhs } -> IsSame<I16>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs += rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs -= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs *= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs /= rhs } -> IsSame<I16&>; });
  STATIC_REQUIRE(requires(I16 lhs, I16 rhs) { { lhs %= rhs } -> IsSame<I16&>; });

  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs + rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs - rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs * rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs / rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs % rhs } -> IsSame<I32>; });

  STATIC_REQUIRE(requires(I16 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I16 lhs, I64 rhs) { { lhs % rhs } -> IsSame<I64>; });
  // clang-format on
}

TEST_CASE("I32", "[integral/types/I32]")
{
  // clang-format off
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs + rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs - rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs * rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs / rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs % rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs += rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs -= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs *= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs /= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I8 rhs) { { lhs %= rhs } -> IsSame<I32&>; });

  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs + rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs - rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs * rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs / rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs % rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs += rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs -= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs *= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs /= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I16 rhs) { { lhs %= rhs } -> IsSame<I32&>; });

  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs + rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs - rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs * rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs / rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs % rhs } -> IsSame<I32>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs += rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs -= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs *= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs /= rhs } -> IsSame<I32&>; });
  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs %= rhs } -> IsSame<I32&>; });

  STATIC_REQUIRE(requires(I32 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I32 lhs, I64 rhs) { { lhs % rhs } -> IsSame<I64>; });
  // clang-format on
}

TEST_CASE("I64", "[integral/types/I64]")
{
  // clang-format off
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs % rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs += rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs -= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs *= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs /= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I8 rhs) { { lhs %= rhs } -> IsSame<I64&>; });

  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs % rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs += rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs -= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs *= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs /= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I16 rhs) { { lhs %= rhs } -> IsSame<I64&>; });

  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs % rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs += rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs -= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs *= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs /= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs %= rhs } -> IsSame<I64&>; });

  STATIC_REQUIRE(requires(I64 lhs, I32 rhs) { { lhs == rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs <= rhs } -> IsSame<bool>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs + rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs - rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs * rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs / rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs % rhs } -> IsSame<I64>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs += rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs -= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs *= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs /= rhs } -> IsSame<I64&>; });
  STATIC_REQUIRE(requires(I64 lhs, I64 rhs) { { lhs %= rhs } -> IsSame<I64&>; });
  // clang-format on
}
