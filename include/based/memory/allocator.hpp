#pragma once

/*
 * Standard: https://eel.is/c++draft/default.allocator
 */

#include "based/concept/is_integral.hpp"
#include "based/integral/types.hpp"
#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T, trait::IsUnsignedIntegral U>
class Allocator;

template<trait::IsUnsignedIntegral U>
class Allocator<void, U>
{
};

template<class T, trait::IsUnsignedIntegral U>
class Allocator
{
public:
  using value_type = T;
  using size_type = U;
  using difference_type = PtrDiffT;
  using propagate_on_container_move_assignment = TrueType;

  constexpr Allocator() noexcept = default;

  template<class T_, trait::IsUnsignedIntegral U_>
  // NOLINTNEXTLINE(*explicit*,*unused*)
  constexpr Allocator(const Allocator<T_, U_>& that) noexcept
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

template<class T, trait::IsUnsignedIntegral U>
constexpr T* Allocator<T, U>::allocate(size_type size)
{
  return static_cast<value_type*>(::operator new(size.value * sizeof(T)));
}

template<class T, trait::IsUnsignedIntegral U>
constexpr void Allocator<T, U>::deallocate(T* ptr, size_type size)
{
  (void)size;
  ::operator delete(static_cast<void*>(ptr));
}

}  // namespace based
