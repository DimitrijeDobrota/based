#pragma once

#include "based/concept/is_same.hpp"

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
struct StrongType
{
  using value_type = StrongType;
  using basic_type = V;  // NOLINT(*identifier*)
  using tag_type = Tag;  // NOLINT(*identifier*)

  basic_type value;

  constexpr ~StrongType() = default;

  explicit constexpr StrongType()
      : value(0)
  {
  }

  explicit constexpr StrongType(basic_type val)
      : value(val)
  {
  }

  explicit constexpr operator basic_type() const { return value; }

  constexpr StrongType(const StrongType&) = default;
  constexpr StrongType(StrongType&&) = default;

  constexpr StrongType& operator=(const StrongType&) = default;
  constexpr StrongType& operator=(StrongType&&) = default;

  template<class T>
  static constexpr Tag underlying_cast(T value)
  {
    return Tag {static_cast<basic_type>(value)};
  }

  template<class T>
  static constexpr Tag cast(T value)
  {
    return static_cast<Tag>(value);
  }
};
// NOLINTEND(*crtp*)
template<class LHS, class RHS>
concept Comparable = requires(LHS lhs, RHS rhs) { compare(lhs, rhs); };

template<class LHS, class RHS>
  requires Comparable<LHS, RHS>
constexpr bool operator==(LHS lhs, RHS rhs)
{
  return lhs.value == rhs.value;
}

template<class LHS, class RHS>
concept Ordered = requires(LHS lhs, RHS rhs) { order(lhs, rhs); };

template<class LHS, class RHS>
  requires Ordered<LHS, RHS>
constexpr auto operator<=>(LHS lhs, RHS rhs)
{
  return lhs.value <=> rhs.value;
}

template<class LHS, class RHS>
concept Addable = requires(LHS lhs, RHS rhs) { add(lhs, rhs); };

template<class LHS, class RHS>
  requires Addable<LHS, RHS>
constexpr auto operator+(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(add(lhs, rhs), lhs.value + rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Addable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(add(lhs, rhs))>;
  })
constexpr auto& operator+=(LHS& lhs, RHS rhs)
{
  return lhs = lhs + rhs;
}

template<class LHS, class RHS>
concept Subtractable = requires(LHS lhs, RHS rhs) { sub(lhs, rhs); };

template<class LHS, class RHS>
  requires Subtractable<LHS, RHS>
constexpr auto operator-(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(sub(lhs, rhs), lhs.value - rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Subtractable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(sub(lhs, rhs))>;
  })
constexpr auto& operator-=(LHS& lhs, RHS rhs)
{
  return lhs = lhs - rhs;
}

template<class LHS, class RHS>
concept Multiplyable = requires(LHS lhs, RHS rhs) { mul(lhs, rhs); };

template<class LHS, class RHS>
  requires Multiplyable<LHS, RHS>
constexpr auto operator*(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(mul(lhs, rhs), lhs.value * rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Multiplyable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(mul(lhs, rhs))>;
  })
constexpr auto& operator*=(LHS& lhs, RHS rhs)
{
  return lhs = lhs * rhs;
}

template<class LHS, class RHS>
concept Divisible = requires(LHS lhs, RHS rhs) { div(lhs, rhs); };

template<class LHS, class RHS>
  requires Divisible<LHS, RHS>
constexpr auto operator/(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(div(lhs, rhs), lhs.value / rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Divisible<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(div(lhs, rhs))>;
  })
constexpr auto& operator/=(LHS& lhs, RHS rhs)
{
  return lhs = lhs / rhs;
}

template<class LHS, class RHS>
concept Modable = requires(LHS lhs, RHS rhs) { mod(lhs, rhs); };

template<class LHS, class RHS>
  requires Modable<LHS, RHS>
constexpr auto operator%(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(mod(lhs, rhs), lhs.value % rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Modable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(mod(lhs, rhs))>;
  })
constexpr auto& operator%=(LHS& lhs, RHS rhs)
{
  return lhs = lhs % rhs;
}

template<class LHS, class RHS>
concept Lshiftable = requires(LHS lhs, RHS rhs) { lshift(lhs, rhs); };

template<class LHS, class RHS>
  requires Lshiftable<LHS, RHS>
constexpr auto operator<<(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lshift(lhs, rhs), lhs.value << rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Lshiftable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(lshift(lhs, rhs))>;
  })
constexpr auto& operator<<=(LHS& lhs, RHS rhs)
{
  return lhs = lhs << rhs;
}

template<class LHS, class RHS>
concept Rshiftable = requires(LHS lhs, RHS rhs) { rshift(lhs, rhs); };

template<class LHS, class RHS>
  requires Rshiftable<LHS, RHS>
constexpr auto operator>>(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(rshift(lhs, rhs), lhs.value >> rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Rshiftable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(rshift(lhs, rhs))>;
  })
constexpr auto& operator>>=(LHS& lhs, RHS rhs)
{
  return lhs = lhs >> rhs;
}

template<class LHS, class RHS>
concept Andable = requires(LHS lhs, RHS rhs) { land(lhs, rhs); };

template<class LHS, class RHS>
  requires Andable<LHS, RHS>
constexpr auto operator&(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(land(lhs, rhs), lhs.value & rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Andable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(land(lhs, rhs))>;
  })
constexpr auto& operator&=(LHS& lhs, RHS rhs)
{
  return lhs = lhs & rhs;
}

template<class LHS, class RHS>
concept Orable = requires(LHS lhs, RHS rhs) { lor(lhs, rhs); };

template<class LHS, class RHS>
  requires Orable<LHS, RHS>
constexpr auto operator|(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lor(lhs, rhs), lhs.value | rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Orable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(lor(lhs, rhs))>;
  })
constexpr auto& operator|=(LHS& lhs, RHS rhs)
{
  return lhs = lhs | rhs;
}

template<class LHS, class RHS>
concept Xorable = requires(LHS lhs, RHS rhs) { lxor(lhs, rhs); };

template<class LHS, class RHS>
  requires Xorable<LHS, RHS>
constexpr auto operator^(LHS lhs, RHS rhs)
{
  return BASED_DETAIL_MACRO(lxor(lhs, rhs), lhs.value ^ rhs.value);
}

template<class LHS, class RHS>
  requires(requires(LHS lhs, RHS rhs) {
    requires Xorable<LHS, RHS>;
    requires trait::IsSame<LHS, decltype(lxor(lhs, rhs))>;
  })
constexpr auto& operator^=(LHS& lhs, RHS rhs)
{
  return lhs = lhs ^ rhs;
}

template<class LHS>
concept Lnotable = requires(LHS lhs) { lnot(lhs); };

template<class LHS>
  requires Lnotable<LHS>
constexpr auto operator~(LHS lhs)
{
  lhs.value = ~lhs.value;
  return lhs;
}

template<class LHS>
concept Unariable = requires(LHS lhs) { unary(lhs); };

template<class LHS>
  requires Unariable<LHS>
constexpr auto operator+(LHS lhs)
{
  return decltype(lhs)(+lhs.value);
}

template<class LHS>
  requires Unariable<LHS>
constexpr auto operator-(LHS lhs)
{
  return decltype(lhs)(-lhs.value);
}

template<class LHS>
concept Preincable = requires(LHS lhs) { preinc(lhs); };

template<class LHS>
  requires Preincable<LHS>
constexpr auto& operator++(LHS& lhs)
{
  ++lhs.value;
  return lhs;
}

template<class LHS>
concept Postincable = requires(LHS lhs) { postinc(lhs); };

template<class LHS>
  requires Postincable<LHS>
constexpr auto operator++(LHS& lhs, int)
{
  return BASED_DETAIL_MACRO(postinc(lhs), lhs.value++);
}

template<class LHS>
concept Predecable = requires(LHS lhs) { predec(lhs); };

template<class LHS>
  requires Predecable<LHS>
constexpr auto operator--(LHS& lhs)
{
  --lhs.value;
  return lhs;
}

template<class LHS>
concept Postdecable = requires(LHS lhs) { postdec(lhs); };

template<class LHS>
  requires Postdecable<LHS>
constexpr auto operator--(LHS& lhs, int)
{
  return BASED_DETAIL_MACRO(postdec(lhs), lhs.value--);
}

#undef BASED_DETAIL_MACRO

}  // namespace based
