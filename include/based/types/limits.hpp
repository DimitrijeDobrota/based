#pragma once

#include "based/types/types.hpp"

namespace based
{

template<class T>
struct limits;

// Signed

template<>
struct limits<i8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i8::basic_cast(0x80);
  static constexpr auto max = i8::basic_cast(0x7F);
};

template<>
struct limits<i16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i16::basic_cast(0x8000);
  static constexpr auto max = i16::basic_cast(0x7FFF);
};

template<>
struct limits<i32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i32::basic_cast(0x80000000);
  static constexpr auto max = i32::basic_cast(0x7FFFFFFF);
};

template<>
struct limits<i64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i64::basic_cast(0x8000000000000000);
  static constexpr auto max = i64::basic_cast(0x7FFFFFFFFFFFFFFF);
};

// Unsigned

template<>
struct limits<u8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u8::basic_cast(0x00);
  static constexpr auto max = u8::basic_cast(0xFF);
};

template<>
struct limits<u16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u16::basic_cast(0x0000);
  static constexpr auto max = u16::basic_cast(0xFFFF);
};

template<>
struct limits<u32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u32::basic_cast(0x00000000);
  static constexpr auto max = u32::basic_cast(0xFFFFFFFF);
};

template<>
struct limits<u64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u64::basic_cast(0x0000000000000000);
  static constexpr auto max = u64::basic_cast(0xFFFFFFFFFFFFFFFF);
};

}  // namespace based
