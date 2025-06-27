#pragma once

/*
 * Standard: https://eel.is/c++draft/default.allocator
 */

#include "based/integral/types.hpp"
#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
class Allocator;

template<>
class Allocator<void>
{
};

template<class T>
class Allocator
{
public:
  using value_type = T;
  using size_type = SizeT;
  using difference_type = PtrDiffT;
  using propagate_on_container_move_assignment = TrueType;

  constexpr Allocator() noexcept = default;

  template<class U>
  // NOLINTNEXTLINE(*explicit*,*unused*)
  constexpr Allocator(const Allocator<U>& that) noexcept
  {
  }

  constexpr Allocator(const Allocator&) noexcept = default;
  constexpr Allocator(Allocator&&) noexcept = default;

  constexpr Allocator& operator=(const Allocator&) noexcept = default;
  constexpr Allocator& operator=(Allocator&&) noexcept = default;

  constexpr ~Allocator() = default;

  constexpr T*   allocate(size_type size);
  constexpr void deallocate(T* ptr, size_type size);
};

template<class T>
constexpr T* Allocator<T>::allocate(Allocator::size_type size)
{
  return static_cast<value_type*>(::operator new(size * sizeof(T)));
}

template<class T>
constexpr void Allocator<T>::deallocate(T* ptr, size_type size)
{
  (void)size;
  ::operator delete(static_cast<void*>(ptr));
}

}  // namespace based
