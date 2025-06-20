#pragma once

#include "based/trait/remove/reference.hpp"

namespace based
{

template<class T>
// NOLINTNEXTLINE(*forward*)
constexpr decltype(auto) move(T&& tmp) noexcept
{
  return static_cast<RemoveReferenceT<T>&&>(tmp);
}

}  // namespace based
