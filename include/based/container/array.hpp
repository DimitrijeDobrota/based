#pragma once

#include <algorithm>

#include "based/concept/is_integral.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"
#include "based/memory/addressof.hpp"

#define TEMPLATE template<class T, trait::IsUnsignedIntegral U, U N>
#define ARRAY Array<T, U, N>

namespace based
{

TEMPLATE
class Array
{
  T m_instance[N != U(0_u) ? N.value + 1 : U(1_u).value];  // NOLINT(*array*)

public:
  using value_type = T;
  using size_type = U;
  using difference_type = PtrDiffT;

  using iterator = value_type*;
  using const_iterator = const value_type*;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  using pointer = T*;
  using const_pointer = const T*;

  using reference = value_type&;
  using const_reference = const value_type&;

  // Element access
  [[nodiscard]] constexpr reference operator[](size_type idx);
  [[nodiscard]] constexpr reference front();
  [[nodiscard]] constexpr reference back();
  [[nodiscard]] constexpr pointer   data();

  [[nodiscard]] constexpr const_reference operator[](size_type idx) const;
  [[nodiscard]] constexpr const_reference front() const;
  [[nodiscard]] constexpr const_reference back() const;
  [[nodiscard]] constexpr const_pointer   data() const;

  // Iterators.
  [[nodiscard]] constexpr iterator begin();
  [[nodiscard]] constexpr iterator end();

  [[nodiscard]] constexpr const_iterator begin() const;
  [[nodiscard]] constexpr const_iterator end() const;

  [[nodiscard]] constexpr const_iterator cbegin() const;
  [[nodiscard]] constexpr const_iterator cend() const;

  [[nodiscard]] constexpr reverse_iterator rbegin();
  [[nodiscard]] constexpr reverse_iterator rend();

  [[nodiscard]] constexpr const_reverse_iterator rbegin() const;
  [[nodiscard]] constexpr const_reverse_iterator rend() const;

  [[nodiscard]] constexpr const_reverse_iterator crbegin() const;
  [[nodiscard]] constexpr const_reverse_iterator crend() const;

  // Capacity
  [[nodiscard]] constexpr size_type size() const;
  [[nodiscard]] constexpr size_type max_size() const;

  [[nodiscard]] constexpr bool empty() const;

  // Operations
  constexpr void fill(const value_type& value);
  constexpr void swap(Array& that) noexcept;
};

TEMPLATE
auto constexpr operator==(const ARRAY& lhs, const ARRAY& rhs) -> bool
{
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

TEMPLATE
auto constexpr operator<=>(const ARRAY& lhs, const ARRAY& rhs)
{
  return std::lexicographical_compare_three_way(
      lhs.begin(), lhs.end(), rhs.begin(), rhs.end()
  );
}

TEMPLATE
inline auto constexpr ARRAY::fill(const ARRAY::value_type& value) -> void
{
  std::fill_n(begin(), size().value, value);
}

TEMPLATE
inline auto constexpr ARRAY::swap(ARRAY& that) noexcept -> void
{
  std::swap_ranges(begin(), end(), that.begin());
}

TEMPLATE
auto constexpr swap(ARRAY& lhs, ARRAY& rhs) noexcept -> void
{
  lhs.swap(rhs);
}

TEMPLATE
inline auto constexpr ARRAY::begin() -> ARRAY::iterator
{
  return iterator(addressof(m_instance[0]));
}

TEMPLATE
inline auto constexpr ARRAY::begin() const -> ARRAY::const_iterator
{
  return const_iterator(addressof(m_instance[0]));
}

TEMPLATE
inline auto constexpr ARRAY::end() -> ARRAY::iterator
{
  // NOLINTNEXTLINE(*array-bounds*)
  return iterator(addressof(m_instance[N.value]));
}

TEMPLATE
inline auto constexpr ARRAY::end() const -> ARRAY::const_iterator
{
  // NOLINTNEXTLINE(*array-bounds*)
  return const_iterator(addressof(m_instance[N.value]));
}

TEMPLATE
inline auto constexpr ARRAY::rbegin() -> ARRAY::reverse_iterator
{
  return reverse_iterator(end());
}

TEMPLATE
inline auto constexpr ARRAY::rbegin() const -> ARRAY::const_reverse_iterator
{
  return const_reverse_iterator(end());
}

TEMPLATE
inline auto constexpr ARRAY::rend() -> ARRAY::reverse_iterator
{
  return reverse_iterator(begin());
}

TEMPLATE
inline auto constexpr ARRAY::rend() const -> ARRAY::const_reverse_iterator
{
  return const_reverse_iterator(begin());
}

TEMPLATE
inline auto constexpr ARRAY::cbegin() const -> ARRAY::const_iterator
{
  return const_iterator(addressof(m_instance[0]));
}

TEMPLATE
inline auto constexpr ARRAY::cend() const -> ARRAY::const_iterator
{
  // NOLINTNEXTLINE(*array-bounds*)
  return const_iterator(addressof(m_instance[N.value]));
}

TEMPLATE
inline auto constexpr ARRAY::crbegin() const -> ARRAY::const_reverse_iterator
{
  return const_reverse_iterator(end());
}

TEMPLATE
inline auto constexpr ARRAY::crend() const -> ARRAY::const_reverse_iterator
{
  return const_reverse_iterator(begin());
}

TEMPLATE
inline auto constexpr ARRAY::operator[](size_type idx) -> ARRAY::reference
{
  return m_instance[idx.value];
}

TEMPLATE
inline auto constexpr ARRAY::operator[](size_type idx) const
    -> ARRAY::const_reference
{
  return m_instance[idx.value];
}

TEMPLATE
inline auto constexpr ARRAY::front() -> ARRAY::reference
{
  return *begin();
}

TEMPLATE
inline auto constexpr ARRAY::front() const -> ARRAY::const_reference
{
  return *begin();
}

TEMPLATE
inline auto constexpr ARRAY::back() -> ARRAY::reference
{
  return N != size_type(0) ? *(end() - 1) : *end();
}

TEMPLATE
inline auto constexpr ARRAY::back() const -> ARRAY::const_reference
{
  return N != size_type(0) ? *(end() - 1) : *end();
}

TEMPLATE
inline auto constexpr ARRAY::data() -> ARRAY::pointer
{
  return addressof(m_instance[0]);
}

TEMPLATE
inline auto constexpr ARRAY::data() const -> ARRAY::const_pointer
{
  return addressof(m_instance[0]);
}

TEMPLATE inline auto constexpr ARRAY::size() const -> ARRAY::size_type
{
  return N;
}

TEMPLATE inline auto constexpr ARRAY::max_size() const -> ARRAY::size_type
{
  return N;
}

TEMPLATE inline auto constexpr ARRAY::empty() const -> bool
{
  return size() == size_type(0);
}

#undef TEMPLATE
#undef ARRAY

}  // namespace based
