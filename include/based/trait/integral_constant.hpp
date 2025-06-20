#pragma once

namespace based
{

template<class T, T v>
struct IntegralConstant
{
  static constexpr T value = v;

  using value_type = T;
  using Type = IntegralConstant;

  // NOLINTNEXTLINE(*explicit*)
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

template<bool b>
using BoolConstant = IntegralConstant<bool, b>;

using TrueType = BoolConstant<true>;
using FalseType = BoolConstant<false>;

}  // namespace based
