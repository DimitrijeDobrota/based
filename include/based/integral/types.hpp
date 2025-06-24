#pragma once

#include "based/integral/strong.hpp"
#include "based/macro/foreach_1.hpp"
#include "based/utility/assert.hpp"

namespace based
{

// NOLINTBEGIN(google-runtime-int)

using SizeT = unsigned long long int;
using PtrDiffT = signed long long int;

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

struct I64 : StrongType<signed long long int, I64>
{
  using StrongType::StrongType;
  using StrongType::operator=;
};

struct I32 : StrongType<signed int, I32>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator I64() { return I64::underlying_cast(value); }

  [[nodiscard]] constexpr I64 to_i64() const { return I64::cast(*this); }
};

struct I16 : StrongType<signed short int, I16>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator I64() { return I64::underlying_cast(value); }
  explicit constexpr operator I32() { return I32::underlying_cast(value); }

  [[nodiscard]] constexpr I64 to_i64() const { return I64::cast(*this); }
  [[nodiscard]] constexpr I32 to_i32() const { return I32::cast(*this); }
};

struct I8 : StrongType<signed char, I8>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator I64() { return I64::underlying_cast(value); }
  explicit constexpr operator I32() { return I32::underlying_cast(value); }
  explicit constexpr operator I16() { return I16::underlying_cast(value); }

  [[nodiscard]] constexpr I64 to_i64() const { return I64::cast(*this); }
  [[nodiscard]] constexpr I32 to_i32() const { return I32::cast(*this); }
  [[nodiscard]] constexpr I16 to_i16() const { return I16::cast(*this); }
};

template<>
struct limits<I8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = I8::underlying_cast(0x80);
  static constexpr auto max = I8::underlying_cast(0x7F);
};

template<>
struct limits<I16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = I16::underlying_cast(0x8000);
  static constexpr auto max = I16::underlying_cast(0x7FFF);
};

template<>
struct limits<I32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = I32::underlying_cast(0x80000000);
  static constexpr auto max = I32::underlying_cast(0x7FFFFFFF);
};

template<>
struct limits<I64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = true;

  static constexpr auto min = I64::underlying_cast(0x8000000000000000);
  static constexpr auto max = I64::underlying_cast(0x7FFFFFFFFFFFFFFF);
};

struct I : StrongType<signed long long int, I>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  consteval operator I8() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<I8>::min.value);
    BASED_ASSERT(value <= limits<I8>::max.value);
    return I8::underlying_cast(value);
  }

  consteval operator I16() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<I16>::min.value);
    BASED_ASSERT(value <= limits<I16>::max.value);
    return I16::underlying_cast(value);
  }

  consteval operator I32() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<I32>::min.value);
    BASED_ASSERT(value <= limits<I32>::max.value);
    return I32::underlying_cast(value);
  }

  consteval operator I64() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<I64>::min.value);
    BASED_ASSERT(value <= limits<I64>::max.value);
    return I64::underlying_cast(value);
  }
};

auto unary(I) -> I;

struct U64 : StrongType<unsigned long long int, U64>
{
  using StrongType::StrongType;
  using StrongType::operator=;
};

struct U32 : StrongType<unsigned int, U32>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator U64() { return U64::underlying_cast(value); }

  [[nodiscard]] constexpr U64 to_u64() const { return U64::cast(*this); }
};

struct U16 : StrongType<unsigned short int, U16>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator U64() { return U64::underlying_cast(value); }
  explicit constexpr operator U32() { return U32::underlying_cast(value); }

  [[nodiscard]] constexpr U64 to_u64() const { return U64::cast(*this); }
  [[nodiscard]] constexpr U32 to_u32() const { return U32::cast(*this); }
};

struct U8 : StrongType<unsigned char, U8>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  explicit constexpr operator U64() { return U64::underlying_cast(value); }
  explicit constexpr operator U32() { return U32::underlying_cast(value); }
  explicit constexpr operator U16() { return U16::underlying_cast(value); }

  [[nodiscard]] constexpr U64 to_u64() const { return U64::cast(*this); }
  [[nodiscard]] constexpr U32 to_u32() const { return U32::cast(*this); }
  [[nodiscard]] constexpr U16 to_u16() const { return U16::cast(*this); }
};

template<>
struct limits<U8>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = U8::underlying_cast(0x00);
  static constexpr auto max = U8::underlying_cast(0xFF);
};

template<>
struct limits<U16>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = U16::underlying_cast(0x0000);
  static constexpr auto max = U16::underlying_cast(0xFFFF);
};

template<>
struct limits<U32>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = U32::underlying_cast(0x00000000);
  static constexpr auto max = U32::underlying_cast(0xFFFFFFFF);
};

template<>
struct limits<U64>
{
  static constexpr bool is_integer = true;
  static constexpr bool is_signed = false;

  static constexpr auto min = U64::underlying_cast(0x0000000000000000);
  static constexpr auto max = U64::underlying_cast(0xFFFFFFFFFFFFFFFF);
};

struct U : StrongType<unsigned long long int, U>
{
  using StrongType::StrongType;

  consteval operator U8() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<U8>::min.value);
    BASED_ASSERT(value <= limits<U8>::max.value);
    return U8::underlying_cast(value);
  }

  consteval operator U16() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<U16>::min.value);
    BASED_ASSERT(value <= limits<U16>::max.value);
    return U16::underlying_cast(value);
  }

  consteval operator U32() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<U32>::min.value);
    BASED_ASSERT(value <= limits<U32>::max.value);
    return U32::underlying_cast(value);
  }

  consteval operator U64() const  // NOLINT(*explicit*)
  {
    BASED_ASSERT(value >= limits<U64>::min.value);
    BASED_ASSERT(value <= limits<U64>::max.value);
    return U64::underlying_cast(value);
  }
};

BASED_FOREACH_1(
    I, BASED_DETAIL_OP_UNARY, unary, preinc, postinc, predec, postdec
)
BASED_FOREACH_1(
    I, BASED_DETAIL_OP_BINARY, compare, order, add, sub, mul, div, mod
)

BASED_FOREACH_1(
    U, BASED_DETAIL_OP_UNARY, preinc, postinc, predec, postdec, lnot
)

BASED_FOREACH_1(
    U,
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
