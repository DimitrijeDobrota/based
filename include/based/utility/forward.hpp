#pragma once

#include "based/trait/is/lvalue_reference.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

template<class T>
constexpr auto forward(remove_reference_t<T>& tmp) noexcept
{
  return static_cast<T&&>(tmp);
}

template<class T>
// NOLINTNEXTLINE(*move*)
constexpr auto forward(remove_reference_t<T>&& tmp) noexcept
{
  static_assert(!is_lvalue_reference_v<T>);
  return static_cast<T&&>(tmp);
}

}  // namespace based
