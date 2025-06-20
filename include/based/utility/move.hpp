#pragma once

#include "based/trait/remove_reference.hpp"

namespace based
{

template<class T>
// NOLINTNEXTLINE(*forward*)
constexpr decltype(auto) move(T&& tmp) noexcept
{
  return static_cast<trait::RemoveReference<T>&&>(tmp);
}

}  // namespace based
