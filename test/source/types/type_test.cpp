#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"
#include "based/types/types.hpp"

using based::SameAs;
using based::u16;
using based::u32;
using based::u64;
using based::u8;

TEST_CASE("u8", "[types/u8]")
{
  // clang-format off
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs + rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs - rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs * rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs / rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs % rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs & rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs | rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs ^ rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs << rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs >> rhs } -> SameAs<u8>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs += rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs -= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs *= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs /= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs %= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs &= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs |= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs ^= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs <<= rhs } -> SameAs<u8&>; });
  STATIC_REQUIRE(requires(u8 lhs, u8 rhs) { { lhs >>= rhs } -> SameAs<u8&>; });

  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs + rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs - rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs * rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs / rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs << rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs >> rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs % rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs & rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs | rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u8 lhs, u16 rhs) { { lhs ^ rhs } -> SameAs<u16>; });

  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs + rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs - rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs * rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs / rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs % rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs << rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs >> rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs & rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs | rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs ^ rhs } -> SameAs<u32>; });

  STATIC_REQUIRE(requires(u8 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u8 lhs, u64 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  // clang-format on
}

TEST_CASE("u16", "[types/u16]")
{
  // clang-format off
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs + rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs - rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs * rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs / rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs % rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs << rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs >> rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs & rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs | rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs ^ rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs += rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs -= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs *= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs /= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs %= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs &= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs |= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs ^= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs <<= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u8 rhs) { { lhs >>= rhs } -> SameAs<u16&>; });

  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs + rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs - rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs * rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs / rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs % rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs << rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs >> rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs & rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs | rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs ^ rhs } -> SameAs<u16>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs += rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs -= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs *= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs /= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs %= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs &= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs |= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs ^= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs <<= rhs } -> SameAs<u16&>; });
  STATIC_REQUIRE(requires(u16 lhs, u16 rhs) { { lhs >>= rhs } -> SameAs<u16&>; });

  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs + rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs - rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs * rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs / rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs % rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs << rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs >> rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs & rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs | rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs ^ rhs } -> SameAs<u32>; });

  STATIC_REQUIRE(requires(u16 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u16 lhs, u64 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  // clang-format on
}

TEST_CASE("u32", "[types/u32]")
{
  // clang-format off
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs + rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs - rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs * rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs / rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs % rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs << rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs >> rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs & rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs | rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs ^ rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs += rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs -= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs *= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs /= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs %= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs &= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs |= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs ^= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs <<= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u8 rhs) { { lhs >>= rhs } -> SameAs<u32&>; });

  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs + rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs - rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs * rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs / rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs % rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs << rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs >> rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs & rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs | rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs ^ rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs += rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs -= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs *= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs /= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs %= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs &= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs |= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs ^= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs <<= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u16 rhs) { { lhs >>= rhs } -> SameAs<u32&>; });

  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs + rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs - rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs * rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs / rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs % rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs << rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs >> rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs & rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs | rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs ^ rhs } -> SameAs<u32>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs += rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs -= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs *= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs /= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs %= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs &= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs |= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs ^= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs <<= rhs } -> SameAs<u32&>; });
  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs >>= rhs } -> SameAs<u32&>; });

  STATIC_REQUIRE(requires(u32 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u32 lhs, u64 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  // clang-format on
}

TEST_CASE("u64", "[types/u64]")
{
  // clang-format off
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs += rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs -= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs *= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs /= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs %= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs &= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs |= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs ^= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs <<= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u8 rhs) { { lhs >>= rhs } -> SameAs<u64&>; });

  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs += rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs -= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs *= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs /= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs %= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs &= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs |= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs ^= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs <<= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u16 rhs) { { lhs >>= rhs } -> SameAs<u64&>; });

  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs += rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs -= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs *= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs /= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs %= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs &= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs |= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs ^= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs <<= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs >>= rhs } -> SameAs<u64&>; });

  STATIC_REQUIRE(requires(u64 lhs, u32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs + rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs - rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs * rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs / rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs % rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs << rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs >> rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs & rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs | rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs ^ rhs } -> SameAs<u64>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs += rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs -= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs *= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs /= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs %= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs &= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs |= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs ^= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs <<= rhs } -> SameAs<u64&>; });
  STATIC_REQUIRE(requires(u64 lhs, u64 rhs) { { lhs >>= rhs } -> SameAs<u64&>; });
  // clang-format on
}

using based::i16;
using based::i32;
using based::i64;
using based::i8;

TEST_CASE("i8", "[types/i8]")
{
  // clang-format off
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs + rhs } -> SameAs<i8>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs - rhs } -> SameAs<i8>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs * rhs } -> SameAs<i8>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs / rhs } -> SameAs<i8>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs % rhs } -> SameAs<i8>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs += rhs } -> SameAs<i8&>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs -= rhs } -> SameAs<i8&>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs *= rhs } -> SameAs<i8&>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs /= rhs } -> SameAs<i8&>; });
  STATIC_REQUIRE(requires(i8 lhs, i8 rhs) { { lhs %= rhs } -> SameAs<i8&>; });

  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs + rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs - rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs * rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs / rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i8 lhs, i16 rhs) { { lhs % rhs } -> SameAs<i16>; });

  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs + rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs - rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs * rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs / rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs % rhs } -> SameAs<i32>; });

  STATIC_REQUIRE(requires(i8 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i8 lhs, i64 rhs) { { lhs % rhs } -> SameAs<i64>; });
  // clang-format on
}

TEST_CASE("i16", "[types/i16]")
{
  // clang-format off
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs + rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs - rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs * rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs / rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs % rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs += rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs -= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs *= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs /= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i8 rhs) { { lhs %= rhs } -> SameAs<i16&>; });

  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs + rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs - rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs * rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs / rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs % rhs } -> SameAs<i16>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs += rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs -= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs *= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs /= rhs } -> SameAs<i16&>; });
  STATIC_REQUIRE(requires(i16 lhs, i16 rhs) { { lhs %= rhs } -> SameAs<i16&>; });

  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs + rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs - rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs * rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs / rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs % rhs } -> SameAs<i32>; });

  STATIC_REQUIRE(requires(i16 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i16 lhs, i64 rhs) { { lhs % rhs } -> SameAs<i64>; });
  // clang-format on
}

TEST_CASE("i32", "[types/i32]")
{
  // clang-format off
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs + rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs - rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs * rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs / rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs % rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs += rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs -= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs *= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs /= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i8 rhs) { { lhs %= rhs } -> SameAs<i32&>; });

  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs + rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs - rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs * rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs / rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs % rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs += rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs -= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs *= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs /= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i16 rhs) { { lhs %= rhs } -> SameAs<i32&>; });

  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs + rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs - rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs * rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs / rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs % rhs } -> SameAs<i32>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs += rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs -= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs *= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs /= rhs } -> SameAs<i32&>; });
  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs %= rhs } -> SameAs<i32&>; });

  STATIC_REQUIRE(requires(i32 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i32 lhs, i64 rhs) { { lhs % rhs } -> SameAs<i64>; });
  // clang-format on
}

TEST_CASE("i64", "[types/i64]")
{
  // clang-format off
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs % rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs += rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs -= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs *= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs /= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i8 rhs) { { lhs %= rhs } -> SameAs<i64&>; });

  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs % rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs += rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs -= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs *= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs /= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i16 rhs) { { lhs %= rhs } -> SameAs<i64&>; });

  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs % rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs += rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs -= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs *= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs /= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs %= rhs } -> SameAs<i64&>; });

  STATIC_REQUIRE(requires(i64 lhs, i32 rhs) { { lhs == rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs <= rhs } -> SameAs<bool>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs + rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs - rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs * rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs / rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs % rhs } -> SameAs<i64>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs += rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs -= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs *= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs /= rhs } -> SameAs<i64&>; });
  STATIC_REQUIRE(requires(i64 lhs, i64 rhs) { { lhs %= rhs } -> SameAs<i64&>; });
  // clang-format on
}
