#pragma once

#include <vector>

namespace based
{

template<class T, class U, class Allocator = std::allocator<T>>
class Vector : public std::vector<T, Allocator>
{
  using Base = std::vector<T, Allocator>;

  static constexpr auto cast(U pos)
  {
    return static_cast<Base::size_type>(pos.value);
  }

  static constexpr auto cast(Base::size_type pos)
  {
    return static_cast<U>(pos);
  }

public:
  using AllocatorType = Allocator;
  using const_iterator = Base::const_iterator;
  using const_pointer = Base::const_pointer;
  using const_reference = Base::const_reference;
  using const_reverse_iterator = Base::const_reverse_iterator;
  using iterator = Base::iterator;
  using pointer = Base::pointer;
  using reference = Base::reference;
  using reverse_iterator = Base::reverse_iterator;
  using value_type = Base::value_type;

  using difference_type = U;
  using size_type = U;

  [[nodiscard]] constexpr const_reference at(size_type pos) const
  {
    return Base::at(cast(pos));
  }

  [[nodiscard]] constexpr reference at(size_type pos)
  {
    return Base::at(cast(pos));
  }

  [[nodiscard]] constexpr const_reference operator[](size_type pos) const
  {
    return Base::operator[](cast(pos));
  }

  [[nodiscard]] constexpr reference operator[](size_type pos)
  {
    return Base::operator[](cast(pos));
  }

  [[nodiscard]] constexpr size_type size() const noexcept
  {
    return cast(Base::size());
  }

  [[nodiscard]] constexpr size_type max_size() const noexcept
  {
    return cast(Base::max_size());
  }

  constexpr void reserve(size_type new_cap) { Base::reserve(cast(new_cap)); }
  constexpr void capacity(size_type new_cap) { Base::capacity(cast(new_cap)); }

  constexpr void resize(size_type new_cap) { Base::resize(cast(new_cap)); }
  constexpr void resize(size_type new_cap, const value_type& value)
  {
    Base::resize(cast(new_cap, value));
  }
};

}  // namespace based
