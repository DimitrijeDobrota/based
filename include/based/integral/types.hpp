#pragma once

#include <compare>

#include "based/utility/assert.hpp"

namespace based
{

// NOLINTBEGIN(google-runtime-int)

using SizeT = unsigned long long int;
using PtrDiffT = signed long long int;

#define BASED_DETAIL_OP_UNARY(Prefix, Name)                                    \
  inline constexpr auto operator Name(Prefix##8 lhs)                           \
  {                                                                            \
    return Prefix##8 ::underlying_cast(Name(lhs.value));                       \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs)                          \
  {                                                                            \
    return Prefix##16 ::underlying_cast(Name(lhs.value));                      \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs)                          \
  {                                                                            \
    return Prefix##32 ::underlying_cast(Name(lhs.value));                      \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs)                          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(Name(lhs.value));                      \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs)                              \
  {                                                                            \
    return Prefix::underlying_cast(Name(lhs.value));                           \
  }

#define BASED_DETAIL_OP_UNARY_PRE(Prefix, Name)                                \
  inline constexpr auto& operator Name(Prefix##8 & lhs)                        \
  {                                                                            \
    Name lhs.value;                                                            \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name(Prefix##16 & lhs)                       \
  {                                                                            \
    Name lhs.value;                                                            \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name(Prefix##32 & lhs)                       \
  {                                                                            \
    Name lhs.value;                                                            \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name(Prefix##64 & lhs)                       \
  {                                                                            \
    Name lhs.value;                                                            \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name(Prefix & lhs)                           \
  {                                                                            \
    Name lhs.value;                                                            \
    return lhs;                                                                \
  }

#define BASED_DETAIL_OP_UNARY_POST(Prefix, Name)                               \
  inline constexpr auto operator Name(Prefix##8 & lhs, int)                    \
  {                                                                            \
    const auto crnt = lhs;                                                     \
    Name       lhs;                                                            \
    return crnt;                                                               \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 & lhs, int)                   \
  {                                                                            \
    const auto crnt = lhs;                                                     \
    Name       lhs;                                                            \
    return crnt;                                                               \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 & lhs, int)                   \
  {                                                                            \
    const auto crnt = lhs;                                                     \
    Name       lhs;                                                            \
    return crnt;                                                               \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 & lhs, int)                   \
  {                                                                            \
    const auto crnt = lhs;                                                     \
    Name       lhs;                                                            \
    return crnt;                                                               \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, int)                         \
  {                                                                            \
    const auto crnt = lhs;                                                     \
    Name       lhs;                                                            \
    return crnt;                                                               \
  }

#define BASED_DETAIL_OP_BINARY(Prefix, Name)                                   \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##8 rhs)            \
  {                                                                            \
    return Prefix##8 ::underlying_cast(lhs.value Name rhs.value);              \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##16 rhs)           \
  {                                                                            \
    return Prefix##16 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##32 rhs)           \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##64 rhs)           \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return Prefix##16 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return Prefix##16 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
                                                                               \
  inline constexpr auto& operator Name##=(Prefix##8 & lhs, Prefix##8 rhs)      \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
                                                                               \
  inline constexpr auto& operator Name##=(Prefix##16 & lhs, Prefix##8 rhs)     \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##16 & lhs, Prefix##16 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
                                                                               \
  inline constexpr auto& operator Name##=(Prefix##32 & lhs, Prefix##8 rhs)     \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##32 & lhs, Prefix##16 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##32 & lhs, Prefix##32 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
                                                                               \
  inline constexpr auto& operator Name##=(Prefix##64 & lhs, Prefix##8 rhs)     \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##64 & lhs, Prefix##16 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##64 & lhs, Prefix##32 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
  inline constexpr auto& operator Name##=(Prefix##64 & lhs, Prefix##64 rhs)    \
  {                                                                            \
    lhs = lhs Name rhs;                                                        \
    return lhs;                                                                \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix lhs, Prefix rhs)                  \
  {                                                                            \
    return Prefix::underlying_cast(lhs.value Name rhs.value);                  \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix lhs, Prefix##8 rhs)               \
  {                                                                            \
    return Prefix##8 ::underlying_cast(lhs.value Name rhs.value);              \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##16 rhs)              \
  {                                                                            \
    return Prefix##16 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##32 rhs)              \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##64 rhs)              \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix rhs)               \
  {                                                                            \
    return Prefix##8 ::underlying_cast(lhs.value Name rhs.value);              \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix rhs)              \
  {                                                                            \
    return Prefix##16 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix rhs)              \
  {                                                                            \
    return Prefix##32 ::underlying_cast(lhs.value Name rhs.value);             \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix rhs)              \
  {                                                                            \
    return Prefix##64 ::underlying_cast(lhs.value Name rhs.value);             \
  }

#define BASED_DETAIL_OP_COMPARE(Prefix, Name)                                  \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##8 rhs)            \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##16 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##32 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix##64 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##8 rhs)           \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##16 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##32 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix##64 rhs)          \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix rhs)                  \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
                                                                               \
  inline constexpr auto operator Name(Prefix lhs, Prefix##8 rhs)               \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##16 rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##32 rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix lhs, Prefix##64 rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##8 lhs, Prefix rhs)               \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##16 lhs, Prefix rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##32 lhs, Prefix rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }                                                                            \
  inline constexpr auto operator Name(Prefix##64 lhs, Prefix rhs)              \
  {                                                                            \
    return (lhs.value Name rhs.value);                                         \
  }

namespace detail
{

template<class V, class Tag>
// NOLINTBEGIN(*crtp*)
struct StrongTypeImpl
{
  using value_type = StrongTypeImpl;
  using underlying_type = V;  // NOLINT(*identifier*)
  using tag_type = Tag;  // NOLINT(*identifier*)

  underlying_type value;

  constexpr ~StrongTypeImpl() = default;

  explicit constexpr StrongTypeImpl()
      : value(0)
  {
  }

  explicit constexpr StrongTypeImpl(underlying_type val)
      : value(val)
  {
  }

  explicit constexpr operator underlying_type() const { return value; }

  constexpr StrongTypeImpl(const StrongTypeImpl&) = default;
  constexpr StrongTypeImpl(StrongTypeImpl&&) = default;

  constexpr StrongTypeImpl& operator=(const StrongTypeImpl&) = default;
  constexpr StrongTypeImpl& operator=(StrongTypeImpl&&) = default;

  template<class T>
  static constexpr Tag underlying_cast(T value)
  {
    return Tag {static_cast<underlying_type>(value)};
  }

  template<class T>
  static constexpr Tag cast(T value)
  {
    return static_cast<Tag>(value);
  }
};
// NOLINTEND(*crtp*)

}  // namespace detail

template<class T>
struct limits;

struct I64 : detail::StrongTypeImpl<signed long long int, I64>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;
};

struct I32 : detail::StrongTypeImpl<signed int, I32>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

  explicit constexpr operator I64() { return I64::underlying_cast(value); }

  [[nodiscard]] constexpr I64 to_i64() const { return I64::cast(*this); }
};

struct I16 : detail::StrongTypeImpl<signed short int, I16>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

  explicit constexpr operator I64() { return I64::underlying_cast(value); }
  explicit constexpr operator I32() { return I32::underlying_cast(value); }

  [[nodiscard]] constexpr I64 to_i64() const { return I64::cast(*this); }
  [[nodiscard]] constexpr I32 to_i32() const { return I32::cast(*this); }
};

struct I8 : detail::StrongTypeImpl<signed char, I8>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

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

struct I : detail::StrongTypeImpl<signed long long int, I>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

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

BASED_DETAIL_OP_UNARY(I, +)
BASED_DETAIL_OP_UNARY(I, -)

BASED_DETAIL_OP_UNARY_PRE(I, ++)
BASED_DETAIL_OP_UNARY_PRE(I, --)

BASED_DETAIL_OP_UNARY_POST(I, ++)
BASED_DETAIL_OP_UNARY_POST(I, --)

BASED_DETAIL_OP_COMPARE(I, ==)
BASED_DETAIL_OP_COMPARE(I, <=>)

BASED_DETAIL_OP_BINARY(I, +)
BASED_DETAIL_OP_BINARY(I, -)
BASED_DETAIL_OP_BINARY(I, *)
BASED_DETAIL_OP_BINARY(I, /)
BASED_DETAIL_OP_BINARY(I, %)

struct U64 : detail::StrongTypeImpl<unsigned long long int, U64>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;
};

struct U32 : detail::StrongTypeImpl<unsigned int, U32>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

  explicit constexpr operator U64() { return U64::underlying_cast(value); }

  [[nodiscard]] constexpr U64 to_u64() const { return U64::cast(*this); }
};

struct U16 : detail::StrongTypeImpl<unsigned short int, U16>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

  explicit constexpr operator U64() { return U64::underlying_cast(value); }
  explicit constexpr operator U32() { return U32::underlying_cast(value); }

  [[nodiscard]] constexpr U64 to_u64() const { return U64::cast(*this); }
  [[nodiscard]] constexpr U32 to_u32() const { return U32::cast(*this); }
};

struct U8 : detail::StrongTypeImpl<unsigned char, U8>
{
  using StrongTypeImpl::StrongTypeImpl;
  using StrongTypeImpl::operator=;

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

struct U : detail::StrongTypeImpl<unsigned long long int, U>
{
  using StrongTypeImpl::StrongTypeImpl;

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

BASED_DETAIL_OP_UNARY(U, +)
BASED_DETAIL_OP_UNARY(U, -)
BASED_DETAIL_OP_UNARY(U, ~)

BASED_DETAIL_OP_UNARY_PRE(U, ++)
BASED_DETAIL_OP_UNARY_PRE(U, --)

BASED_DETAIL_OP_UNARY_POST(U, ++)
BASED_DETAIL_OP_UNARY_POST(U, --)

BASED_DETAIL_OP_COMPARE(U, ==)
BASED_DETAIL_OP_COMPARE(U, <=>)

BASED_DETAIL_OP_BINARY(U, +)
BASED_DETAIL_OP_BINARY(U, -)
BASED_DETAIL_OP_BINARY(U, *)
BASED_DETAIL_OP_BINARY(U, /)
BASED_DETAIL_OP_BINARY(U, %)
BASED_DETAIL_OP_BINARY(U, <<)
BASED_DETAIL_OP_BINARY(U, >>)
BASED_DETAIL_OP_BINARY(U, &)
BASED_DETAIL_OP_BINARY(U, |)
BASED_DETAIL_OP_BINARY(U, ^)

#undef BASED_DETAIL_OP_UNARY_PRE
#undef BASED_DETAIL_OP_UNARY_POST
#undef BASED_DETAIL_OP_BINARY
#undef BASED_DETAIL_OP_COMPARE

// NOLINTEND(google-runtime-int)

}  // namespace based
