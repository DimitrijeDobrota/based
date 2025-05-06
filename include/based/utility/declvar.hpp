#pragma once

#include "based/trait/add/rvalue_reference.hpp"

namespace based
{

template<typename T>
add_rvalue_reference_t<T> declval() noexcept
{
  static_assert(false, "declval not allowed in an evaluated context");
}

}  // namespace based
