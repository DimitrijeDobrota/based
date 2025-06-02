#pragma once

#include "based/macro/foreach_1.hpp"
#include "based/types/strong.hpp"

namespace based
{

// NOLINTBEGIN(google-runtime-int)

using bi8 = signed char;
using bi16 = signed short int;
using bi32 = signed int;
using bi64 = signed long long int;

using bu8 = unsigned char;
using bu16 = unsigned short int;
using bu32 = unsigned int;
using bu64 = unsigned long long int;

using size_t = bu64;

struct i64 : strong_type<signed long long int, i64>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

struct i32 : strong_type<signed int, i32>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::basic_cast(value); }
};

struct i16 : strong_type<signed short int, i16>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::basic_cast(value); }
  explicit constexpr operator i32() { return i32::basic_cast(value); }
};

struct i8 : strong_type<signed char, i8>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator i64() { return i64::basic_cast(value); }
  explicit constexpr operator i32() { return i32::basic_cast(value); }
  explicit constexpr operator i16() { return i16::basic_cast(value); }
};

struct u64 : strong_type<unsigned long long int, u64>
{
  using strong_type::strong_type;
  using strong_type::operator=;
};

struct u32 : strong_type<unsigned int, u32>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::basic_cast(value); }
};

struct u16 : strong_type<unsigned short int, u16>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::basic_cast(value); }
  explicit constexpr operator u32() { return u32::basic_cast(value); }
};

struct u8 : strong_type<unsigned char, u8>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr operator u64() { return u64::basic_cast(value); }
  explicit constexpr operator u32() { return u32::basic_cast(value); }
  explicit constexpr operator u16() { return u16::basic_cast(value); }
};

#define BASED_DETAIL_OP_UNARY(Prefix, Name, Index)                             \
  auto Name(Prefix##8)->Prefix##8;                                             \
  auto Name(Prefix##16)->Prefix##16;                                           \
  auto Name(Prefix##32)->Prefix##32;                                           \
  auto Name(Prefix##64)->Prefix##64;

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
  auto Name(Prefix##64, Prefix##64)->Prefix##64;

BASED_FOREACH_1(
    i, BASED_DETAIL_OP_UNARY, unary, preinc, postinc, predec, postdec
)
BASED_FOREACH_1(
    i, BASED_DETAIL_OP_BINARY, compare, order, add, sub, mul, div, mod
)

BASED_FOREACH_1(u, BASED_DETAIL_OP_UNARY, preinc, postinc, predec, postdec)
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
