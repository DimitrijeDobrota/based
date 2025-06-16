#pragma once

#include "based/types/types.hpp"

// NOLINTBEGIN(google-runtime-int)

namespace based
{

namespace literals
{

consteval auto operator""_i(unsigned long long val)
{
  return i::underlying_cast(val);
}

consteval i8 operator""_i8(unsigned long long val)
{
  return i::underlying_cast(val);
}

consteval i16 operator""_i16(unsigned long long val)
{
  return i::underlying_cast(val);
}

consteval i32 operator""_i32(unsigned long long val)
{
  return i::underlying_cast(val);
}

consteval i64 operator""_i64(unsigned long long val)
{
  return i::underlying_cast(val);
}

}  // namespace literals

// Unsigned

namespace literals
{

consteval auto operator""_u(unsigned long long val)
{
  return u::underlying_cast(val);
}

consteval u8 operator""_u8(unsigned long long val)
{
  return u::underlying_cast(val);
}

consteval u16 operator""_u16(unsigned long long val)
{
  return u::underlying_cast(val);
}

consteval u32 operator""_u32(unsigned long long val)
{
  return u::underlying_cast(val);
}

consteval u64 operator""_u64(unsigned long long val)
{
  return u::underlying_cast(val);
}

}  // namespace literals

using namespace literals;  // NOLINT(*namespace*)

}  // namespace based

// NOLINTEND(google-runtime-int)
