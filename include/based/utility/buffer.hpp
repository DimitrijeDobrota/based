#pragma once

#include <concepts>
#include <cstring>
#include <utility>

#include "based/integral/types.hpp"
#include "based/utility/forward.hpp"

namespace based
{

/* ----- Buffer used for Local Buffer Optimization ----- */

template<size_t size, size_t alignment = alignof(void*)>
struct Buffer
{
  template<typename T>
  static constexpr bool valid_type()
  {
    return sizeof(T) <= size && (alignment % sizeof(T)) == 0;
  }

  alignas(alignment) char m_space[size] = {0};  // NOLINT(*array*)

  Buffer() = default;

  template<typename T, typename... Args>
    requires(valid_type<T>() && std::constructible_from<T, Args...>)
  explicit Buffer(
      std::in_place_type_t<T> /* t */, Args&&... args
  ) noexcept(std::is_nothrow_constructible_v<T, Args...>)
  {
    static_assert(std::is_trivially_destructible_v<T>);
    static_assert(std::is_trivially_copyable_v<T>);
    ::new (static_cast<void*>(as<T>())) T(based::forward<Args>(args)...);
  }

  template<typename T, typename... Args>
    requires(valid_type<T>() && std::constructible_from<T, Args...>)
  T* emplace(Args&&... args
  ) noexcept(std::is_nothrow_constructible_v<T, Args...>)
  {
    static_assert(std::is_trivially_destructible_v<T>);
    static_assert(std::is_trivially_copyable_v<T>);

    // NOLINTNEXTLINE(*owning-memory*)
    return ::new (static_cast<void*>(as<T>())) T(based::forward<Args>(args)...);
  }

  template<typename T>
    requires(valid_type<T>())
  [[nodiscard]] T* as() noexcept
  {
    return reinterpret_cast<T*>(&m_space);  // NOLINT(*reinterpret-cast*)
  }

  template<typename T>
    requires(valid_type<T>())
  [[nodiscard]] const T* as() const noexcept
  {
    return const_cast<Buffer*>(this)->as<T>();  // NOLINT(*const-cast*)
  }

  void swap(Buffer& that) noexcept
  {
    // NOLINTBEGIN(*array*)
    alignas(alignment) char tmp[size];
    ::memcpy(tmp, this->m_space, size);
    ::memcpy(this->m_space, that.m_space, size);
    ::memcpy(that.m_space, tmp, size);
    // NOLINTEND(*array*)
  }
};

}  // namespace based
