#pragma once

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iterator>
#include <memory>

#include "based/concept/is_constructible.hpp"
#include "based/concept/is_integral.hpp"
#include "based/integral/literals.hpp"
#include "based/integral/types.hpp"
#include "based/memory/addressof.hpp"
#include "based/memory/allocator.hpp"
#include "based/utility/forward.hpp"
#include "based/utility/move.hpp"

namespace based
{

#define TEMPLATE template<class T, trait::IsUnsignedIntegral U, class Allocator>
#define VECTOR Vector<T, U, Allocator>

template<
    class T,
    trait::IsUnsignedIntegral U,
    class Allocator = Allocator<T, U>>
class Vector
{
  static constexpr auto initial_capacity = U(1);

  Allocator m_allocator {};
  T*        m_instance = nullptr;
  U         m_size = 0_u;
  U         m_capacity = 0_u;

public:
  using value_type = T;
  using size_type = U;
  using difference_type = PtrDiffT;
  using allocator_type = Allocator;

  using iterator = value_type*;
  using const_iterator = const value_type*;

  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  using pointer = T*;
  using const_pointer = const T*;

  using reference = value_type&;
  using const_reference = const value_type&;
  constexpr Vector() noexcept(noexcept(allocator_type()));
  constexpr explicit Vector(const allocator_type& alloc) noexcept;
  constexpr explicit Vector(size_type cnt, const allocator_type& alloc = {});

  constexpr Vector(
      size_type cnt, const value_type& value, const allocator_type& alloc = {}
  );

  template<class Itr>
  constexpr Vector(Itr first, Itr last, const allocator_type& alloc = {});

  Vector(
      std::initializer_list<value_type> init, const allocator_type& alloc = {}
  );

  constexpr Vector(const Vector& other);
  constexpr Vector(const Vector& other, const allocator_type& alloc);

  constexpr Vector(Vector&& other) noexcept;
  constexpr Vector(Vector&& other, const allocator_type& alloc);

  constexpr Vector& operator=(const Vector& other);
  constexpr Vector& operator=(Vector&& other) noexcept;
  constexpr Vector& operator=(std::initializer_list<value_type> ilist);

  constexpr ~Vector() noexcept;

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
  [[nodiscard]] constexpr size_type capacity() const;

  constexpr void reserve(size_type new_capacity);

  [[nodiscard]] constexpr bool empty() const;

  // Operations
  constexpr void swap(Vector& that) noexcept;
  constexpr void clear();
  constexpr void pop_back();

  constexpr void resize(size_type new_size);
  constexpr void resize(size_type new_size, const value_type& value);

  template<class Itr>
  constexpr iterator insert(const_iterator pos, Itr first, Itr last);
  constexpr iterator insert(const_iterator pos, const value_type& value);
  constexpr iterator insert(const_iterator pos, value_type&& value);
  constexpr iterator insert(
      const_iterator pos, size_type cnt, const value_type& value
  );
  constexpr iterator insert(const_iterator pos, std::initializer_list<T> ilist);

  template<class... Args>
    requires trait::IsConstructible<value_type, Args...>
  constexpr iterator emplace(const_iterator pos, Args&&... args);

  constexpr iterator erase(const_iterator pos);
  constexpr iterator erase(const_iterator first, const_iterator last);

  constexpr void push_back(const value_type& value);
  constexpr void push_back(value_type&& value);

  template<class... Args>
    requires trait::IsConstructible<value_type, Args...>
  constexpr reference emplace_back(Args&&... args);

private:
  template<class... Args>
  constexpr void construct_at(T* ptr, Args&&... args);
  constexpr void destroy_range(T* from, T* end) noexcept;
  constexpr void move_elements(T* dst, T* src, size_type count);
  constexpr void copy_elements(T* dst, const T* src, size_type count);
  constexpr void assert_in_bounds(size_type idx) const;
  constexpr void allocate_memory(size_type new_capacity);
  constexpr void deallocate_memory();

  [[nodiscard]] constexpr bool is_full() const noexcept;
};

// NOLINTBEGIN(*pointer-arithmetic*)

TEMPLATE
constexpr VECTOR::~Vector() noexcept
{
  deallocate_memory();
}

TEMPLATE
constexpr VECTOR::Vector() noexcept(noexcept(VECTOR::allocator_type()))
    : Vector(allocator_type())
{
  // This constructor is intentionally empty.
  // It initializes the vector with the default allocator.
}

TEMPLATE
constexpr VECTOR::Vector(const allocator_type& alloc) noexcept
    : m_allocator(alloc)
    , m_instance(m_allocator.allocate(initial_capacity))
    , m_size(0_u)
    , m_capacity(initial_capacity)
{
}

TEMPLATE
constexpr VECTOR::Vector(size_type cnt, const allocator_type& alloc)
    : m_allocator(alloc)
    , m_instance(m_allocator.allocate(cnt))
    , m_size(cnt)
    , m_capacity(cnt)
{
  std::memset(m_instance, 0, cnt.value * sizeof(value_type));
}

TEMPLATE
constexpr VECTOR::Vector(
    size_type cnt, const value_type& value, const allocator_type& alloc
)
    : m_allocator(alloc)
    , m_instance(m_allocator.allocate(cnt))
    , m_size(cnt)
    , m_capacity(cnt)
{
  std::fill_n(m_instance, cnt.value, value);
}

TEMPLATE
template<class Itr>
constexpr VECTOR::Vector(Itr first, Itr last, const allocator_type& alloc)
    : Vector(alloc)
{
  auto count = size_type::underlying_cast(std::distance(first, last));
  m_size = count;
  m_capacity = count;

  if (count > 0_u) {
    m_instance = m_allocator.allocate(count);
    std::uninitialized_copy(first, last, m_instance);
  }
}

TEMPLATE
VECTOR::Vector(std::initializer_list<T> init, const allocator_type& alloc)
    : Vector(init.begin(), init.end(), alloc)
{
}

TEMPLATE
constexpr auto operator==(const VECTOR& lhs, const VECTOR& rhs) -> bool
{
  if (lhs.size() != rhs.size()) {
    return false;
  }

  return std::equal(
      std::begin(lhs), std::end(lhs), std::begin(rhs), std::end(rhs)
  );
}

TEMPLATE
constexpr auto operator<=>(const VECTOR& lhs, const VECTOR& rhs)
{
  if (lhs.size() < rhs.size()) {
    return std::strong_ordering::less;
  }

  if (lhs.size() > rhs.size()) {
    return std::strong_ordering::greater;
  }

  return std::lexicographical_compare_three_way(
      std::begin(lhs), std::end(lhs), std::begin(rhs), std::end(rhs)
  );
}

TEMPLATE constexpr VECTOR::Vector(const Vector& other)
    : Vector(other, other.m_allocator)
{
}

TEMPLATE constexpr VECTOR::Vector(
    const Vector& other, const allocator_type& alloc
)
    : m_allocator(alloc)
    , m_instance(m_allocator.allocate(other.m_capacity))
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
  copy_elements(m_instance, other.m_instance, m_size);
}

TEMPLATE constexpr VECTOR::Vector(Vector&& other) noexcept
    : Vector(based::move(other), other.m_allocator)
{
  // This constructor initializes the vector by moving another vector.
  // It transfers ownership of the resources from the other vector to this one.
  // The other vector is left in a valid but unspecified state.
}

TEMPLATE constexpr VECTOR::Vector(Vector&& other, const allocator_type& alloc)
    : m_allocator(alloc)
    , m_instance(other.m_instance)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
  // This constructor initializes the vector by moving another vector
  // using the specified allocator.
  // It transfers ownership of the resources from the other vector to this one.
  // The other vector is left in a valid but unspecified state.
  other.m_instance = nullptr;
  other.m_size = 0_u;
  other.m_capacity = 0_u;
}

TEMPLATE constexpr auto VECTOR::operator=(const VECTOR& other) -> Vector&
{
  if (this == &other) {
    return *this;
  }

  if (m_instance != nullptr) {
    m_allocator.deallocate(m_instance, m_capacity);
  }

  m_allocator = other.m_allocator;
  m_size = other.m_size;
  m_capacity = other.m_capacity;

  m_instance = m_allocator.allocate(m_capacity);
  copy_elements(m_instance, other.m_instance, m_size);

  return *this;
}

TEMPLATE constexpr auto VECTOR::operator=(VECTOR&& other) noexcept -> Vector&
{
  if (this == &other) {
    return *this;
  }

  if (m_instance != nullptr) {
    m_allocator.deallocate(m_instance, m_capacity);
  }

  m_allocator = based::move(other.m_allocator);
  m_instance = other.m_instance;
  m_size = other.m_size;
  m_capacity = other.m_capacity;

  other.m_instance = nullptr;
  other.m_size = 0_u;
  other.m_capacity = 0_u;

  return *this;
}

TEMPLATE constexpr auto VECTOR::operator=(
    std::initializer_list<typename VECTOR::value_type> ilist
) -> Vector&
{
  if (m_instance != nullptr) {
    m_allocator.deallocate(m_instance, m_capacity);
  }

  m_size = size_type::underlying_cast(ilist.size());
  m_capacity = m_size;

  if (m_size > 0_u) {
    m_instance = m_allocator.allocate(m_size);
    copy_elements(m_instance, ilist.begin(), m_size);
  } else {
    m_instance = nullptr;
  }

  return *this;
}

TEMPLATE
constexpr auto swap(VECTOR& lhs, VECTOR& rhs) noexcept -> void
{
  lhs.swap(rhs);
}

TEMPLATE
inline constexpr auto VECTOR::begin() -> VECTOR::iterator
{
  return iterator(addressof(m_instance[0]));
}

TEMPLATE
inline constexpr auto VECTOR::begin() const -> VECTOR::const_iterator
{
  return const_iterator(addressof(m_instance[0]));
}

TEMPLATE
inline constexpr auto VECTOR::end() -> VECTOR::iterator
{
  return iterator(addressof(m_instance[m_size.value]));
}

TEMPLATE
inline constexpr auto VECTOR::end() const -> VECTOR::const_iterator
{
  return const_iterator(addressof(m_instance[m_size.value]));
}

TEMPLATE
inline constexpr auto VECTOR::rbegin() -> VECTOR::reverse_iterator
{
  return reverse_iterator(end());
}

TEMPLATE
inline constexpr auto VECTOR::rbegin() const -> VECTOR::const_reverse_iterator
{
  return const_reverse_iterator(end());
}

TEMPLATE
inline constexpr auto VECTOR::rend() -> VECTOR::reverse_iterator
{
  return reverse_iterator(begin());
}

TEMPLATE
inline constexpr auto VECTOR::rend() const -> VECTOR::const_reverse_iterator
{
  return const_reverse_iterator(begin());
}

TEMPLATE
inline constexpr auto VECTOR::cbegin() const -> VECTOR::const_iterator
{
  return const_iterator(addressof(m_instance[0]));
}

TEMPLATE
inline constexpr auto VECTOR::cend() const -> VECTOR::const_iterator
{
  return const_iterator(addressof(m_instance[m_size.value]));
}

TEMPLATE
inline constexpr auto VECTOR::crbegin() const -> VECTOR::const_reverse_iterator
{
  return const_reverse_iterator(end());
}

TEMPLATE
inline constexpr auto VECTOR::crend() const -> VECTOR::const_reverse_iterator
{
  return const_reverse_iterator(begin());
}

TEMPLATE
inline constexpr auto VECTOR::operator[](size_type idx) -> VECTOR::reference
{
  assert_in_bounds(idx);
  return m_instance[idx.value];
}

TEMPLATE
inline constexpr auto VECTOR::operator[](size_type idx) const
    -> VECTOR::const_reference
{
  assert_in_bounds(idx);
  return m_instance[idx.value];
}

TEMPLATE
inline constexpr auto VECTOR::front() -> VECTOR::reference
{
  assert(m_size > 0_u && "front() called on empty vector");
  return m_instance[0];
}

TEMPLATE
inline constexpr auto VECTOR::front() const -> VECTOR::const_reference
{
  assert(m_size > 0_u && "front() called on empty vector");
  return m_instance[0];
}

TEMPLATE
inline constexpr auto VECTOR::back() -> VECTOR::reference
{
  assert(m_size > 0_u && "back() called on empty vector");
  return m_instance[(m_size - 1_u).value];
}

TEMPLATE
inline constexpr auto VECTOR::back() const -> VECTOR::const_reference
{
  return m_instance[(m_size - 1_u).value];
}

TEMPLATE
inline constexpr auto VECTOR::data() -> VECTOR::pointer
{
  return addressof(m_instance[0]);
}

TEMPLATE
inline constexpr auto VECTOR::data() const -> VECTOR::const_pointer
{
  return addressof(m_instance[0]);
}

TEMPLATE inline constexpr auto VECTOR::size() const -> VECTOR::size_type
{
  return m_size;
}

TEMPLATE inline constexpr auto VECTOR::max_size() const -> VECTOR::size_type
{
  return limits<size_type>::max;
}

TEMPLATE inline constexpr auto VECTOR::capacity() const -> VECTOR::size_type
{
  return m_capacity;
}

TEMPLATE inline constexpr auto VECTOR::reserve(size_type new_capacity) -> void
{
  if (new_capacity > m_capacity) {
    auto new_instance = m_allocator.allocate(new_capacity);
    move_elements(new_instance, m_instance, m_size);
    m_allocator.deallocate(m_instance, m_capacity);
    m_instance = new_instance;
    m_capacity = new_capacity;
  }
}

TEMPLATE inline constexpr auto VECTOR::empty() const -> bool
{
  return size() == 0_u;
}

TEMPLATE
inline constexpr auto VECTOR::swap(VECTOR& that) noexcept -> void
{
  using std::swap;

  swap(m_allocator, that.m_allocator);
  swap(m_instance, that.m_instance);
  swap(m_size, that.m_size);
  swap(m_capacity, that.m_capacity);
}

TEMPLATE inline constexpr auto VECTOR::clear() -> void
{
  if (m_instance != nullptr) {
    m_allocator.deallocate(m_instance, m_capacity);
    m_instance = nullptr;
  }
  m_size = 0_u;
  m_capacity = 0_u;
}

TEMPLATE inline constexpr auto VECTOR::pop_back() -> void
{
  // TODO: assert that m_size > 0
  if (m_size > 0_u) {
    --m_size;
  }
}

TEMPLATE
template<class Itr>
inline constexpr auto VECTOR::insert(const_iterator pos, Itr first, Itr last)
    -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  auto count = size_type::underlying_cast(std::distance(first, last));

  if (is_full()) {
    allocate_memory(m_capacity + count);
  }

  if (index < m_size) {
    std::memmove(
        m_instance + index.value + count.value,
        m_instance + index.value,
        (m_size - index).value * sizeof(value_type)
    );
  }

  std::uninitialized_copy(first, last, m_instance + index.value);
  m_size += count;

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::insert(
    const_iterator pos, const value_type& value
) -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  if (is_full()) {
    allocate_memory(m_capacity * 2_u);
  }

  if (index < m_size) {
    std::memmove(
        m_instance + index.value + 1,
        m_instance + index.value,
        (m_size - index).value * sizeof(value_type)
    );
  }

  m_instance[index.value] = value;
  ++m_size;

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::insert(
    const_iterator pos, value_type&& value
) -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  if (is_full()) {
    allocate_memory(m_capacity * 2_u);
  }

  if (index < m_size) {
    std::memmove(
        m_instance + index.value + 1,
        m_instance + index.value,
        (m_size - index).value * sizeof(value_type)
    );
  }

  m_instance[index.value] = based::move(value);
  ++m_size;

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::insert(
    const_iterator pos, size_type cnt, const value_type& value
) -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  if (is_full()) {
    allocate_memory(m_capacity + cnt);
  }

  if (index < m_size) {
    std::memmove(
        m_instance + index.value + cnt.value,
        m_instance + index.value,
        (m_size - index).value * sizeof(value_type)
    );
  }

  std::fill_n(m_instance + index.value, cnt.value, value);
  m_size += cnt;

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::insert(
    const_iterator pos, std::initializer_list<T> ilist
) -> VECTOR::iterator
{
  return insert(pos, ilist.begin(), ilist.end());
}

TEMPLATE
template<class... Args>
  requires trait::IsConstructible<typename VECTOR::value_type, Args...>
inline constexpr auto VECTOR::emplace(const_iterator pos, Args&&... args)
    -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  if (is_full()) {
    allocate_memory(m_capacity * 2_u);
  }

  if (index < m_size) {
    std::memmove(
        m_instance + index.value + 1,
        m_instance + index.value,
        (m_size - index).value * sizeof(value_type)
    );
  }

  m_instance[index.value] = value_type(based::forward<Args>(args)...);
  ++m_size;

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::erase(const_iterator pos)
    -> VECTOR::iterator
{
  auto index = size_type::underlying_cast(pos - begin());
  if (index < m_size) {
    std::memmove(
        m_instance + index.value,
        m_instance + index.value + 1,
        (m_size - index - 1_u).value * sizeof(value_type)
    );
    --m_size;
  }

  return begin() + index.value;
}

TEMPLATE inline constexpr auto VECTOR::erase(
    const_iterator first, const_iterator last
) -> VECTOR::iterator
{
  auto first_index = size_type::underlying_cast(first - begin());
  auto last_index = size_type::underlying_cast(last - begin());

  if (first_index < m_size && last_index <= m_size) {
    auto count = last_index - first_index;
    std::memmove(
        m_instance + first_index.value,
        m_instance + last_index.value,
        (m_size - last_index).value * sizeof(value_type)
    );
    m_size -= count;
  }

  return begin() + first_index.value;
}

TEMPLATE inline constexpr auto VECTOR::push_back(const value_type& value)
    -> void
{
  if (is_full()) {
    allocate_memory(m_capacity == 0_u ? initial_capacity : m_capacity * 2_u);
  }
  construct_at(m_instance + m_size.value, value);
  ++m_size;
}

TEMPLATE inline constexpr auto VECTOR::push_back(value_type&& value) -> void
{
  if (is_full()) {
    allocate_memory(m_capacity == 0_u ? initial_capacity : m_capacity * 2_u);
  }
  construct_at(m_instance + m_size.value, based::move(value));
  ++m_size;
}

TEMPLATE
template<class... Args>
  requires trait::IsConstructible<typename VECTOR::value_type, Args...>
inline constexpr auto VECTOR::emplace_back(Args&&... args) -> VECTOR::reference
{
  if (is_full()) {
    allocate_memory(m_capacity == 0_u ? initial_capacity : m_capacity * 2_u);
  }

  construct_at(m_instance + m_size.value, based::forward<Args>(args)...);
  ++m_size;
  return m_instance[(m_size - 1_u).value];
}

TEMPLATE
constexpr auto VECTOR::resize(size_type new_size) -> void
{
  // Helper function to resize the vector.
  if (new_size > m_capacity) {
    allocate_memory(new_size);
  }

  m_size = new_size;

  if (m_instance != nullptr) {
    std::memset(
        m_instance + m_size.value,
        0,
        (m_capacity - m_size).value * sizeof(value_type)
    );
  }
}

TEMPLATE
constexpr auto VECTOR::resize(size_type new_size, const value_type& value)
    -> void
{
  // Helper function to resize the vector with a specific value.
  if (new_size > m_capacity) {
    allocate_memory(new_size);
  }

  if (new_size > m_size) {
    std::fill_n(
        m_instance + m_size.value, new_size.value - m_size.value, value
    );
  } else {
    destroy_range(m_instance + new_size.value, m_instance + m_size.value);
  }

  m_size = new_size;
}

TEMPLATE
[[nodiscard]] constexpr auto VECTOR::is_full() const noexcept -> bool
{
  // Helper function to check if the vector is full.
  return m_size == m_capacity;
}

TEMPLATE
constexpr auto VECTOR::destroy_range(T* from, T* end) noexcept -> void
{
  for (; from != end; ++from) {
    from->~T();
  }
}

TEMPLATE
template<class... Args>
constexpr auto VECTOR::construct_at(T* ptr, Args&&... args) -> void
{
  ::new (static_cast<void*>(ptr)) T(based::forward<Args>(args)...);
}

TEMPLATE
constexpr auto VECTOR::move_elements(T* dst, T* src, size_type count) -> void
{
  for (U i = 0_u; i < count; ++i) {
    construct_at(dst + i.value, based::move(src[i.value]));
  }
}

TEMPLATE
constexpr auto VECTOR::copy_elements(T* dst, const T* src, size_type count)
    -> void
{
  for (U i = 0_u; i < count; ++i) {
    construct_at(dst + i.value, src[i.value]);
  }
}

TEMPLATE
constexpr void VECTOR::assert_in_bounds(size_type idx) const
{
  assert(idx.value < m_size.value && "Vector index out of bounds");
}

TEMPLATE
inline constexpr auto VECTOR::allocate_memory(size_type new_capacity) -> void
{
  if (new_capacity <= m_capacity) {
    return;
  }

  T* new_instance = m_allocator.allocate(new_capacity);
  try {
    move_elements(new_instance, m_instance, m_size);
  } catch (...) {
    m_allocator.deallocate(new_instance, new_capacity);
    throw;
  }
  destroy_range(m_instance, m_instance + m_size.value);
  if (m_instance) {
    m_allocator.deallocate(m_instance, m_capacity);
  }
  m_instance = new_instance;
  m_capacity = new_capacity;
}

TEMPLATE
inline constexpr auto VECTOR::deallocate_memory() -> void
{
  if (m_instance != nullptr) {
    destroy_range(m_instance, m_instance + m_size.value);
    m_allocator.deallocate(m_instance, m_capacity);
    m_instance = nullptr;
  }
  m_size = 0_u;
  m_capacity = 0_u;
}

// NOLINTEND(*pointer-arithmetic*)

#undef TEMPLATE
#undef VECTOR

}  // namespace based
