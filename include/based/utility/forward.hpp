#pragma once

#include "based/concept/is_lvalue_reference.hpp"
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
  static_assert(!trait::IsLvalueReference<T>);
  return static_cast<T&&>(tmp);
}

}  // namespace based
