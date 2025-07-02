#pragma once

#include "based/integral/types.hpp"

// NOLINTBEGIN(google-runtime-int)

namespace based
{

namespace literals
{

consteval auto operator""_i(unsigned long long val)
{
  return I::underlying_cast(val);
}

consteval I8 operator""_i8(unsigned long long val)
{
  return I::underlying_cast(val);
}

consteval I16 operator""_i16(unsigned long long val)
{
  return I::underlying_cast(val);
}

consteval I32 operator""_i32(unsigned long long val)
{
  return I::underlying_cast(val);
}

consteval I64 operator""_i64(unsigned long long val)
{
  return I::underlying_cast(val);
}

}  // namespace literals

// Unsigned

namespace literals
{

consteval auto operator""_u(unsigned long long val)
{
  return U::underlying_cast(val);
}

consteval U8 operator""_u8(unsigned long long val)
{
  return U::underlying_cast(val);
}

consteval U16 operator""_u16(unsigned long long val)
{
  return U::underlying_cast(val);
}

consteval U32 operator""_u32(unsigned long long val)
{
  return U::underlying_cast(val);
}

consteval U64 operator""_u64(unsigned long long val)
{
  return U::underlying_cast(val);
}

}  // namespace literals

using namespace literals;  // NOLINT(*namespace*)

}  // namespace based

// NOLINTEND(google-runtime-int)
