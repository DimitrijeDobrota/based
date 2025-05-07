#pragma once

namespace based
{

template<class T, T v>
struct integral_constant
{
  static constexpr T value = v;

  using value_type = T;
  using type = integral_constant;

  // NOLINTNEXTLINE(*explicit*)
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

template<bool b>
using bool_constant = integral_constant<bool, b>;

using true_type = bool_constant<true>;
using false_type = bool_constant<false>;

}  // namespace based
