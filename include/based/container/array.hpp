#pragma once

#include <array>

#include "based/integral/types.hpp"

namespace based
{

template<class T, class U, U n>
class Array : public std::array<T, U64::cast(n).value>
{
  using Base = std::array<T, U64::cast(n).value>;

  static constexpr auto cast(U pos)
  {
    return static_cast<Base::size_type>(pos.value);
  }

  static constexpr auto cast(Base::size_type pos)
  {
    return static_cast<U>(pos.value);
  }

public:
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
};

}  // namespace based
