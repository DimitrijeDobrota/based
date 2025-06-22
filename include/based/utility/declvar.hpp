#pragma once

#include "based/trait/add_rvalue_reference.hpp"

namespace based
{

template<typename T>
trait::AddRValueReference<T> declval() noexcept
{
  static_assert(false, "declval not allowed in an evaluated context");
}

}  // namespace based
