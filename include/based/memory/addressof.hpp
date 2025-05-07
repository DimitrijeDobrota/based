#pragma once

#include "based/trait/is/object.hpp"

namespace based
{

template<class T>
T* addressof(T& arg) noexcept
{
  return &arg;
}

template<class T>
  requires is_object_v<T>
T* addressof(T& arg) noexcept
{
  // NOLINTBEGIN(*reinterpret*,*const*)
  return reinterpret_cast<T*>(
      &const_cast<char&>(reinterpret_cast<const volatile char&>(arg))
  );
  // NOLINTEND(*reinterpret*,*const*)
}

}  // namespace based
