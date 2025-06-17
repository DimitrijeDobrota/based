#pragma once

#include "based/assert.hpp"
#include "based/macro/foreach_1.hpp"
#include "based/types/strong.hpp"

namespace based
{

// NOLINTBEGIN(google-runtime-int)

using size_t = unsigned long long int;

#define BASED_DETAIL_OP_UNARY(Prefix, Name, Index)                             \
  auto Name(Prefix##8)->Prefix##8;                                             \
  auto Name(Prefix##16)->Prefix##16;                                           \
  auto Name(Prefix##32)->Prefix##32;                                           \
  auto Name(Prefix##64)->Prefix##64;                                           \
  auto Name(Prefix)->Prefix;

#define BASED_DETAIL_OP_BINARY(Prefix, Name, Index)                            \
  auto Name(Prefix##8, Prefix##8)->Prefix##8;                                  \
  auto Name(Prefix##8, Prefix##16)->Prefix##16;                                \
  auto Name(Prefix##8, Prefix##32)->Prefix##32;                                \
  auto Name(Prefix##8, Prefix##64)->Prefix##64;                                \
                                                                               \
  auto Name(Prefix##16, Prefix##8)->Prefix##16;                                \
  auto Name(Prefix##16, Prefix##16)->Prefix##16;                               \
  auto Name(Prefix##16, Prefix##32)->Prefix##32;                               \
  auto Name(Prefix##16, Prefix##64)->Prefix##64;                               \
                                                                               \
  auto Name(Prefix##32, Prefix##8)->Prefix##32;                                \
  auto Name(Prefix##32, Prefix##16)->Prefix##32;                               \
  auto Name(Prefix##32, Prefix##32)->Prefix##32;                               \
  auto Name(Prefix##32, Prefix##64)->Prefix##64;                               \
                                                                               \
  auto Name(Prefix##64, Prefix##8)->Prefix##64;                                \
  auto Name(Prefix##64, Prefix##16)->Prefix##64;                               \
  auto Name(Prefix##64, Prefix##32)->Prefix##64;                               \
  auto Name(Prefix##64, Prefix##64)->Prefix##64;                               \
                                                                               \
  auto Name(Prefix, Prefix)->Prefix;

template<class T>
struct limits;

struct i64 : strong_type<signed long long int, i64>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

struct i32 : strong_type<signed int, i32>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::underlying_cast(value); }

  [[nodiscard]] constexpr i64 to_i64() const { return i64::cast(*this); }
};

struct i16 : strong_type<signed short int, i16>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::underlying_cast(value); }
  explicit constexpr operator i32() { return i32::underlying_cast(value); }

  [[nodiscard]] constexpr i64 to_i64() const { return i64::cast(*this); }
  [[nodiscard]] constexpr i32 to_i32() const { return i32::cast(*this); }
};

struct i8 : strong_type<signed char, i8>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::underlying_cast(value); }
  explicit constexpr operator i32() { return i32::underlying_cast(value); }
  explicit constexpr operator i16() { return i16::underlying_cast(value); }

  [[nodiscard]] constexpr i64 to_i64() const { return i64::cast(*this); }
  [[nodiscard]] constexpr i32 to_i32() const { return i32::cast(*this); }
  [[nodiscard]] constexpr i16 to_i16() const { return i16::cast(*this); }
};

template<>
struct limits<i8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i8::underlying_cast(0x80);
  static constexpr auto max = i8::underlying_cast(0x7F);
};

template<>
struct limits<i16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i16::underlying_cast(0x8000);
  static constexpr auto max = i16::underlying_cast(0x7FFF);
};

template<>
struct limits<i32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i32::underlying_cast(0x80000000);
  static constexpr auto max = i32::underlying_cast(0x7FFFFFFF);
};

template<>
struct limits<i64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = i64::underlying_cast(0x8000000000000000);
  static constexpr auto max = i64::underlying_cast(0x7FFFFFFFFFFFFFFF);
};

struct i : strong_type<signed long long int, i>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  consteval operator i8() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<i8>::min.value);
    BASED_ASSERT(value <= limits<i8>::max.value);
    return i8::underlying_cast(value);
  }

  consteval operator i16() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<i16>::min.value);
    BASED_ASSERT(value <= limits<i16>::max.value);
    return i16::underlying_cast(value);
  }

  consteval operator i32() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<i32>::min.value);
    BASED_ASSERT(value <= limits<i32>::max.value);
    return i32::underlying_cast(value);
  }

  consteval operator i64() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<i64>::min.value);
    BASED_ASSERT(value <= limits<i64>::max.value);
    return i64::underlying_cast(value);
  }
};

auto unary(i) -> i;

struct u64 : strong_type<unsigned long long int, u64>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

struct u32 : strong_type<unsigned int, u32>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::underlying_cast(value); }

  [[nodiscard]] constexpr u64 to_u64() const { return u64::cast(*this); }
};

struct u16 : strong_type<unsigned short int, u16>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::underlying_cast(value); }
  explicit constexpr operator u32() { return u32::underlying_cast(value); }

  [[nodiscard]] constexpr u64 to_u64() const { return u64::cast(*this); }
  [[nodiscard]] constexpr u32 to_u32() const { return u32::cast(*this); }
};

struct u8 : strong_type<unsigned char, u8>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::underlying_cast(value); }
  explicit constexpr operator u32() { return u32::underlying_cast(value); }
  explicit constexpr operator u16() { return u16::underlying_cast(value); }

  [[nodiscard]] constexpr u64 to_u64() const { return u64::cast(*this); }
  [[nodiscard]] constexpr u32 to_u32() const { return u32::cast(*this); }
  [[nodiscard]] constexpr u16 to_u16() const { return u16::cast(*this); }
};

template<>
struct limits<u8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u8::underlying_cast(0x00);
  static constexpr auto max = u8::underlying_cast(0xFF);
};

template<>
struct limits<u16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u16::underlying_cast(0x0000);
  static constexpr auto max = u16::underlying_cast(0xFFFF);
};

template<>
struct limits<u32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u32::underlying_cast(0x00000000);
  static constexpr auto max = u32::underlying_cast(0xFFFFFFFF);
};

template<>
struct limits<u64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = u64::underlying_cast(0x0000000000000000);
  static constexpr auto max = u64::underlying_cast(0xFFFFFFFFFFFFFFFF);
};

struct u : strong_type<unsigned long long int, u>
{
  using strong_type::strong_type;

  consteval operator u8() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<u8>::min.value);
    BASED_ASSERT(value <= limits<u8>::max.value);
    return u8::underlying_cast(value);
  }

  consteval operator u16() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<u16>::min.value);
    BASED_ASSERT(value <= limits<u16>::max.value);
    return u16::underlying_cast(value);
  }

  consteval operator u32() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<u32>::min.value);
    BASED_ASSERT(value <= limits<u32>::max.value);
    return u32::underlying_cast(value);
  }

  consteval operator u64() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<u64>::min.value);
    BASED_ASSERT(value <= limits<u64>::max.value);
    return u64::underlying_cast(value);
  }
};

BASED_FOREACH_1(
    i, BASED_DETAIL_OP_UNARY, unary, preinc, postinc, predec, postdec
)
BASED_FOREACH_1(
    i, BASED_DETAIL_OP_BINARY, compare, order, add, sub, mul, div, mod
)

BASED_FOREACH_1(
    u, BASED_DETAIL_OP_UNARY, preinc, postinc, predec, postdec, lnot
)

BASED_FOREACH_1(
    u,
    BASED_DETAIL_OP_BINARY,
    compare,
    order,
    add,
    sub,
    mul,
    div,
    mod,
    lshift,
    rshift,
    land,
    lor,
    lxor
)

#undef BASED_DETAIL_TYPE
#undef BASED_DETAIL_OP_UNARY
#undef BASED_DETAIL_OP_BINARY

// NOLINTEND(google-runtime-int)

}  // namespace based
