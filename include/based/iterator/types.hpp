#pragma once

#include "based/concept/is_convertible.hpp"
#include "based/concept/is_same.hpp"
#include "based/integral/types.hpp"

namespace based
{

namespace iterator
{

class Type
{
  template<
      class Category,
      class T,
      class Distance = PtrDiffT,
      class Pointer = T*,
      class Reference = T&>
  struct Iterator
  {
    using iterator_category = Category;
    using value_type = T;
    using difference_type = Distance;
    using pointer = Pointer;
    using reference = Reference;
  };
};

}  // namespace iterator

using IteratorType = iterator::Type;

namespace reverse_iterator
{

template<class Itr>
class Type
{
protected:
  Itr m_current = Itr();  // NOLINT(*visibility*)

public:
  Type() = default;
  constexpr explicit Type(Itr itr)
      : m_current(itr)
  {
  }

  template<class U>
    requires(!trait::IsSame<U, Itr> && trait::IsConvertible<const U&, Itr>)
  constexpr explicit Type(const U& other)
      : m_current(other.base())
  {
  }

  friend constexpr bool operator==(const Type& lhs, const Type& rhs) = default;
  friend constexpr auto operator<=>(const Type& lhs, const Type& rhs) = default;

  constexpr decltype(auto) operator*() const
  {
    return *std::prev(m_current);  // <== returns the content of prev
  }

  constexpr Type& operator++()
  {
    --m_current;
    return *this;
  }

  constexpr Type operator++(int)
  {
    auto tmp = *this;
    ++(*this);
    return tmp;
  }

  constexpr Type& operator--()
  {
    ++m_current;
    return *this;
  }

  constexpr Type operator--(int)
  {
    auto tmp = *this;
    --(*this);
    return tmp;
  }

  constexpr Itr base() const { return m_current; }

  // Other member functions, friend functions, and member typedefs are not shown
  // here.
};

}  // namespace reverse_iterator

}  // namespace based
