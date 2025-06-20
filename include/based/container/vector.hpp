#pragma once

#include <vector>

namespace based
{

template<class T, class U, class Allocator = std::allocator<T>>
class Vector : public std::vector<T, Allocator>
{
  using base = std::vector<T, Allocator>;

  static constexpr auto cast(U pos)
  {
    return static_cast<base::size_type>(pos.value);
  }

  static constexpr auto cast(base::size_type pos)
  {
    return static_cast<U>(pos);
  }

public:
  using allocator_type = Allocator;
  using const_iterator = base::const_iterator;
  using const_pointer = base::const_pointer;
  using const_reference = base::const_reference;
  using const_reverse_iterator = base::const_reverse_iterator;
  using iterator = base::iterator;
  using pointer = base::pointer;
  using reference = base::reference;
  using reverse_iterator = base::reverse_iterator;
  using value_type = base::value_type;

  using difference_type = U;
  using size_type = U;

  [[nodiscard]] constexpr const_reference at(size_type pos) const
  {
    return base::at(cast(pos));
  }

  [[nodiscard]] constexpr reference at(size_type pos)
  {
    return base::at(cast(pos));
  }

  [[nodiscard]] constexpr const_reference operator[](size_type pos) const
  {
    return base::operator[](cast(pos));
  }

  [[nodiscard]] constexpr reference operator[](size_type pos)
  {
    return base::operator[](cast(pos));
  }

  [[nodiscard]] constexpr size_type size() const noexcept
  {
    return cast(base::size());
  }

  [[nodiscard]] constexpr size_type max_size() const noexcept
  {
    return cast(base::max_size());
  }

  constexpr void reserve(size_type new_cap) { base::reserve(cast(new_cap)); }
  constexpr void capacity(size_type new_cap) { base::capacity(cast(new_cap)); }

  constexpr void resize(size_type new_cap) { base::resize(cast(new_cap)); }
  constexpr void resize(size_type new_cap, const value_type& value)
  {
    base::resize(cast(new_cap, value));
  }
};

}  // namespace based
