#pragma once
#include "based/macro/foreach_1.hpp"
#include "based/types/strong.hpp"

namespace based
{

// NOLINTBEGIN(google-runtime-int)

using bi8 = signed char;
using bi16 = signed short int;
using bi32 = signed int;
using bi64 = signed long int;

using bu8 = unsigned char;
using bu16 = unsigned short int;
using bu32 = unsigned int;
using bu64 = unsigned long int;

using size_t = bu64;

#define BASED_DETAIL_TYPE(Name)                                                             \
  /* NOLINTNEXTLINE(*macro*) */                                                \
  struct Name : strong_type<b##Name, Name>                                     \
  {                                                                            \
    using strong_type::strong_type;                                            \
    using strong_type::operator=;                                              \
  };                                                                           \
                                                                               \
  namespace literals                                                           \
  {                                                                            \
  constexpr auto operator""_##Name(unsigned long long val)                     \
  {                                                                            \
    /* NOLINTNEXTLINE(*macro*) */                                              \
    return Name {static_cast<Name::basic_type>(val)};                          \
  }                                                                            \
  }  // namespace literals

BASED_DETAIL_TYPE(i8)
BASED_DETAIL_TYPE(i16)
BASED_DETAIL_TYPE(i32)
BASED_DETAIL_TYPE(i64)

BASED_DETAIL_TYPE(u8)
BASED_DETAIL_TYPE(u16)
BASED_DETAIL_TYPE(u32)
BASED_DETAIL_TYPE(u64)

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

BASED_FOREACH_1(i, BASED_DETAIL_OP_UNARY, preinc, postinc, predec, postdec)
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
