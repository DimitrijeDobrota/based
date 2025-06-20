#pragma once

#include "based/trait/is/lvalue_reference.hpp"
#include "based/trait/remove_reference.hpp"

namespace based
{

template<class T>
constexpr decltype(auto) forward(trait::RemoveReference<T>& tmp) noexcept
{
  return static_cast<T&&>(tmp);
}

template<class T>
// NOLINTNEXTLINE(*move*)
constexpr decltype(auto) forward(trait::RemoveReference<T>&& tmp) noexcept
{
  static_assert(!is_lvalue_reference_v<T>);
  return static_cast<T&&>(tmp);
}

}  // namespace based
