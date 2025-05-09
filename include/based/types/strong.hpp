#pragma once

#include "based/concepts/is/same.hpp"

namespace based
{

// NOLINTNEXTLINE(*macro*)
#define BASED_DETAIL_MACRO(decl, val)                                          \
  decltype(decl)                                                               \
  {                                                                            \
    static_cast<decltype(decl)::value_type>(val)                               \
  }

template<class ValueType, class Tag>
// NOLINTNEXTLINE(*crtp*)
struct strong_type
{
  using value_type = ValueType;
  using tag_type = Tag;

  ValueType value;
};

template<class LHS, class RHS>
concept addable = requires(LHS lhs, RHS rhs) { add(lhs, rhs); };

template<class LHS, class RHS>
  requires addable<LHS, RHS>
constexpr auto operator+(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(add(lhs, rhs), lhs.value + rhs.value);
}

template<class LHS, class RHS>
concept subtractable = requires(LHS lhs, RHS rhs) { sub(lhs, rhs); };

template<class LHS, class RHS>
  requires subtractable<LHS, RHS>
constexpr auto operator-(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(sub(lhs, rhs), lhs.value - rhs.value);
}

template<class LHS, class RHS>
concept multiplyable = requires(LHS lhs, RHS rhs) { mul(lhs, rhs); };

template<class LHS, class RHS>
  requires multiplyable<LHS, RHS>
constexpr auto operator*(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(mul(lhs, rhs), lhs.value * rhs.value);
}

template<class LHS, class RHS>
concept divisible = requires(LHS lhs, RHS rhs) { div(lhs, rhs); };

template<class LHS, class RHS>
  requires divisible<LHS, RHS>
constexpr auto operator/(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(div(lhs, rhs), lhs.value / rhs.value);
}

template<class LHS, class RHS>
concept modable = requires(LHS lhs, RHS rhs) { mod(lhs, rhs); };

template<class LHS, class RHS>
  requires modable<LHS, RHS>
constexpr auto operator%(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(mod(lhs, rhs), lhs.value % rhs.value);
}

template<class LHS>
concept preincable = requires(LHS lhs) { preinc(lhs); };

template<class LHS>
  requires preincable<LHS>
constexpr auto& operator++(LHS& lhs)
{
  ++lhs.value;
  return lhs;
}

template<class LHS>
concept postincable = requires(LHS lhs) { postinc(lhs); };

template<class LHS>
  requires postincable<LHS>
constexpr auto operator++(LHS& lhs, int)
{
  return BASED_DETAIL_MACRO(postinc(lhs), lhs.value++);
}

template<class LHS>
concept predecable = requires(LHS lhs) { predec(lhs); };

template<class LHS>
  requires predecable<LHS>
constexpr auto operator--(LHS& lhs)
{
  --lhs.value;
  return lhs;
}

template<class LHS>
concept postdecable = requires(LHS lhs) { postdec(lhs); };

template<class LHS>
  requires postdecable<LHS>
constexpr auto operator--(LHS lhs, int)
{
  return BASED_DETAIL_MACRO(postdec(lhs), lhs.value--);
}

template<class LHS>
concept neggable = requires(LHS lhs) { lneg(lhs); };

template<class LHS>
  requires neggable<LHS>
constexpr auto operator~(LHS lhs)
{
  return BASED_DETAIL_MACRO(lneg(lhs), ~lhs.value);
}

template<class LHS, class RHS>
concept andable = requires(LHS lhs, RHS rhs) { land(lhs, rhs); };

template<class LHS, class RHS>
  requires andable<LHS, RHS>
constexpr auto operator&(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(land(lhs, rhs), lhs.value & rhs.value);
}

template<class LHS, class RHS>
concept orable = requires(LHS lhs, RHS rhs) { lor(lhs, rhs); };

template<class LHS, class RHS>
  requires orable<LHS, RHS>
constexpr auto operator|(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lor(lhs, rhs), lhs.value | rhs.value);
}

template<class LHS, class RHS>
concept xorable = requires(LHS lhs, RHS rhs) { lxor(lhs, rhs); };

template<class LHS, class RHS>
  requires xorable<LHS, RHS>
constexpr auto operator^(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lxor(lhs, rhs), lhs.value ^ rhs.value);
}

template<class LHS, class RHS = LHS>
concept equal_addable = requires(LHS lhs, RHS rhs) { eadd(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_addable<LHS, RHS>
constexpr auto& operator+=(LHS& lhs, RHS rhs)
{
  lhs.value += rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_subtractable = requires(LHS lhs, RHS rhs) { esub(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_subtractable<LHS, RHS>
constexpr auto& operator-=(LHS& lhs, RHS rhs)
{
  lhs.value -= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_multiplyable = requires(LHS lhs, RHS rhs) { emul(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_multiplyable<LHS, RHS>
constexpr auto& operator*=(LHS& lhs, RHS rhs)
{
  lhs.value *= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_divisible = requires(LHS lhs, RHS rhs) { ediv(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_divisible<LHS, RHS>
constexpr auto& operator/=(LHS& lhs, RHS rhs)
{
  lhs.value /= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_modable = requires(LHS lhs, RHS rhs) { emod(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_modable<LHS, RHS>
constexpr auto& operator%=(LHS& lhs, RHS rhs)
{
  lhs.value %= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_andable = requires(LHS lhs, RHS rhs) { eland(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_andable<LHS, RHS>
constexpr auto& operator&=(LHS& lhs, RHS rhs)
{
  lhs.value &= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_orable = requires(LHS lhs, RHS rhs) { elor(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_orable<LHS, RHS>
constexpr auto& operator|=(LHS& lhs, RHS rhs)
{
  lhs.value |= rhs.value;
  return lhs;
}

template<class LHS, class RHS = LHS>
concept equal_xorable = requires(LHS lhs, RHS rhs) { elxor(lhs, rhs); };

template<class LHS, class RHS = LHS>
  requires equal_xorable<LHS, RHS>
constexpr auto& operator^=(LHS& lhs, RHS rhs)
{
  lhs.value ^= rhs.value;
  return lhs;
}

template<class LHS, class RHS>
concept equalable = requires(LHS lhs, RHS rhs) {
  {
    equal(lhs, rhs)
  } -> SameAs<bool>;
};

template<class LHS, class RHS>
  requires equalable<LHS, RHS>
constexpr bool operator==(LHS lhs, RHS rhs)
{
  return lhs.value == rhs.value;
}

#undef BASED_DETAIL_MACRO

}  // namespace based
