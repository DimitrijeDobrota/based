#pragma once

#include "based/concepts/is/same.hpp"

namespace based
{

// NOLINTNEXTLINE(*macro*)
#define BASED_DETAIL_MACRO(decl, val)                                          \
  decltype(decl)                                                               \
  {                                                                            \
    static_cast<decltype(decl)::basic_type>(val)                               \
  }

template<class V, class Tag>
// NOLINTBEGIN(*crtp*)
struct strong_type
{
  using value_type = strong_type;
  using basic_type = V;
  using tag_type = Tag;

  constexpr ~strong_type() = default;

  constexpr explicit strong_type()
      : value(0)
  {
  }

  constexpr explicit strong_type(basic_type val)
      : value(val)
  {
  }

  constexpr strong_type(const strong_type&) = default;
  constexpr strong_type(strong_type&&) = default;

  constexpr strong_type& operator=(const strong_type&) = default;
  constexpr strong_type& operator=(strong_type&&) = default;

  basic_type value;
};
// NOLINTEND(*crtp*)

template<class LHS, class RHS>
concept comparable = requires(LHS lhs, RHS rhs) { compare(lhs, rhs); };

template<class LHS, class RHS>
  requires comparable<LHS, RHS>
constexpr bool operator==(LHS lhs, RHS rhs)
{
  return lhs.value == rhs.value;
}

template<class LHS, class RHS>
concept ordered = requires(LHS lhs, RHS rhs) { order(lhs, rhs); };

template<class LHS, class RHS>
  requires ordered<LHS, RHS>
constexpr auto operator<=>(LHS lhs, RHS rhs)
{
  return lhs.value <=> rhs.value;
}

template<class LHS, class RHS>
concept addable = requires(LHS lhs, RHS rhs) { add(lhs, rhs); };

template<class LHS, class RHS>
  requires addable<LHS, RHS>
constexpr auto operator+(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(add(lhs, rhs), lhs.value + rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires addable<LHS, RHS>;
    requires SameAs<LHS, decltype(add(lhs, rhs))>;
  })
constexpr auto& operator+=(LHS& lhs, RHS rhs)
{
  return lhs = lhs + rhs;
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
  requires(requires(LHS lhs, RHS rhs) {
    requires subtractable<LHS, RHS>;
    requires SameAs<LHS, decltype(sub(lhs, rhs))>;
  })
constexpr auto& operator-=(LHS& lhs, RHS rhs)
{
  return lhs = lhs - rhs;
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
  requires(requires(LHS lhs, RHS rhs) {
    requires multiplyable<LHS, RHS>;
    requires SameAs<LHS, decltype(mul(lhs, rhs))>;
  })
constexpr auto& operator*=(LHS& lhs, RHS rhs)
{
  return lhs = lhs * rhs;
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
  requires(requires(LHS lhs, RHS rhs) {
    requires divisible<LHS, RHS>;
    requires SameAs<LHS, decltype(div(lhs, rhs))>;
  })
constexpr auto& operator/=(LHS& lhs, RHS rhs)
{
  return lhs = lhs / rhs;
}

template<class LHS, class RHS>
concept modable = requires(LHS lhs, RHS rhs) { mod(lhs, rhs); };

template<class LHS, class RHS>
  requires modable<LHS, RHS>
constexpr auto operator%(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(mod(lhs, rhs), lhs.value % rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires modable<LHS, RHS>;
    requires SameAs<LHS, decltype(mod(lhs, rhs))>;
  })
constexpr auto& operator%=(LHS& lhs, RHS rhs)
{
  return lhs = lhs % rhs;
}

template<class LHS, class RHS>
concept lshiftable = requires(LHS lhs, RHS rhs) { lshift(lhs, rhs); };

template<class LHS, class RHS>
  requires lshiftable<LHS, RHS>
constexpr auto operator<<(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lshift(lhs, rhs), lhs.value << rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires lshiftable<LHS, RHS>;
    requires SameAs<LHS, decltype(lshift(lhs, rhs))>;
  })
constexpr auto& operator<<=(LHS& lhs, RHS rhs)
{
  return lhs = lhs << rhs;
}

template<class LHS, class RHS>
concept rshiftable = requires(LHS lhs, RHS rhs) { rshift(lhs, rhs); };

template<class LHS, class RHS>
  requires rshiftable<LHS, RHS>
constexpr auto operator>>(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(rshift(lhs, rhs), lhs.value >> rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires rshiftable<LHS, RHS>;
    requires SameAs<LHS, decltype(rshift(lhs, rhs))>;
  })
constexpr auto& operator>>=(LHS& lhs, RHS rhs)
{
  return lhs = lhs >> rhs;
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
  requires(requires(LHS lhs, RHS rhs) {
    requires andable<LHS, RHS>;
    requires SameAs<LHS, decltype(land(lhs, rhs))>;
  })
constexpr auto& operator&=(LHS& lhs, RHS rhs)
{
  return lhs = lhs & rhs;
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
  requires(requires(LHS lhs, RHS rhs) {
    requires orable<LHS, RHS>;
    requires SameAs<LHS, decltype(lor(lhs, rhs))>;
  })
constexpr auto& operator|=(LHS& lhs, RHS rhs)
{
  return lhs = lhs | rhs;
}

template<class LHS, class RHS>
concept xorable = requires(LHS lhs, RHS rhs) { lxor(lhs, rhs); };

template<class LHS, class RHS>
  requires xorable<LHS, RHS>
constexpr auto operator^(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lxor(lhs, rhs), lhs.value ^ rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires xorable<LHS, RHS>;
    requires SameAs<LHS, decltype(lxor(lhs, rhs))>;
  })
constexpr auto& operator^=(LHS& lhs, RHS rhs)
{
  return lhs = lhs ^ rhs;
}

template<class LHS>
concept lnotable = requires(LHS lhs) { lnot(lhs); };

template<class LHS>
  requires lnotable<LHS>
constexpr auto operator~(LHS lhs)
{
  lhs.value = ~lhs.value;
  return lhs;
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

#undef BASED_DETAIL_MACRO

}  // namespace based
