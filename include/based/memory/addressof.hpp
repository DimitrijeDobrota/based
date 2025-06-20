#pragma once

#include "based/concept/is_object.hpp"

namespace based
{

template<class T>
T* addressof(T& arg) noexcept
{
  return &arg;
}

template<class T>
  requires trait::IsObject<T>
T* addressof(T& arg) noexcept
{
  // NOLINTBEGIN(*reinterpret*,*const*)
  return reinterpret_cast<T*>(
      &const_cast<char&>(reinterpret_cast<const volatile char&>(arg))
  );
  // NOLINTEND(*reinterpret*,*const*)
}

}  // namespace based
