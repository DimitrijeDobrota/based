#pragma once

namespace based
{

template<class T, T v>
struct IntegralConstant
{
  static constexpr T value = v;

  using value_type = T;
  using type = IntegralConstant;

  // NOLINTNEXTLINE(*explicit*)
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

template<bool b>
using bool_constant = IntegralConstant<bool, b>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

}  // namespace based
