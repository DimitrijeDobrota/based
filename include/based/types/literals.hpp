#pragma once

#include "based/char/is/digit.hpp"
#include "based/concepts/is/castable.hpp"
#include "based/types/limits.hpp"
#include "based/types/types.hpp"

// NOLINTBEGIN(google-runtime-int)

namespace based
{

// Signed

namespace detail
{

template<signed long long val>
constexpr auto make_signed_itnernal()
{
  if constexpr (val <= limits<i8>::max.value) {
    return i8::basic_cast(val);
  } else if constexpr (val <= limits<i16>::max.value) {
    return i16::basic_cast(val);
  } else if constexpr (val <= limits<i32>::max.value) {
    return i32::basic_cast(val);
  } else {
    return i64::basic_cast(val);
  }
}

template<signed long long v, char c, char... cs>
constexpr auto make_signed_itnernal()
{
  const signed long long radix = 10;

  static_assert(is_digit(character(c)), "invalid digit");
  static_assert(v <= (limits<i64>::max.value - (c - '0')) / radix, "overflow");

  return make_signed_itnernal<(radix * v) + (c - '0'), cs...>();
}

template<char... cs>
constexpr auto make_signed()
{
  return make_signed_itnernal<0, cs...>();
}

}  // namespace detail

namespace literals
{

template<char... cs>
auto operator"" _i()
{
  return detail::make_signed<cs...>();
}

template<char... cs>
  requires CastableTo<decltype(detail::make_signed<cs...>()), u8>
consteval auto operator"" _i8()
{
  return static_cast<u8>(detail::make_signed<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_signed<cs...>()), u16>
consteval auto operator"" _i16()
{
  return static_cast<u16>(detail::make_signed<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_signed<cs...>()), u32>
consteval auto operator"" _i32()
{
  return static_cast<u32>(detail::make_signed<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_signed<cs...>()), u64>
consteval auto operator"" _i64()
{
  return static_cast<u64>(detail::make_signed<cs...>());
}

}  // namespace literals

// Unsigned

namespace detail
{

template<unsigned long long val>
constexpr auto make_unsigned_internal()
{
  if constexpr (val <= limits<u8>::max.value) {
    return u8::basic_cast(val);
  } else if constexpr (val <= limits<u16>::max.value) {
    return u16::basic_cast(val);
  } else if constexpr (val <= limits<u32>::max.value) {
    return u32::basic_cast(val);
  } else {
    return u64::basic_cast(val);
  }
}

template<unsigned long long v, char c, char... cs>
constexpr auto make_unsigned_internal()
{
  const unsigned long long radix = 10;

  static_assert(is_digit(character(c)), "invalid digit");
  static_assert(v <= (limits<u64>::max.value - (c - '0')) / radix, "overflow");

  return make_unsigned_internal<(radix * v) + c - '0', cs...>();
}

template<char... cs>
constexpr auto make_unsigned()
{
  return make_unsigned_internal<0, cs...>();
}

}  // namespace detail

namespace literals
{

template<char... cs>
auto operator"" _u()
{
  return detail::make_unsigned<cs...>();
}

template<char... cs>
  requires CastableTo<decltype(detail::make_unsigned<cs...>()), u8>
consteval auto operator"" _u8()
{
  return static_cast<u8>(detail::make_unsigned<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_unsigned<cs...>()), u16>
consteval auto operator"" _u16()
{
  return static_cast<u16>(detail::make_unsigned<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_unsigned<cs...>()), u32>
consteval auto operator"" _u32()
{
  return static_cast<u32>(detail::make_unsigned<cs...>());
}

template<char... cs>
  requires CastableTo<decltype(detail::make_unsigned<cs...>()), u64>
consteval auto operator"" _u64()
{
  return static_cast<u64>(detail::make_unsigned<cs...>());
}

}  // namespace literals

using namespace literals;  // NOLINT(*namespace*)
}  // namespace based

// NOLINTEND(google-runtime-int)
