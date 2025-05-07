#pragma once

#include "based/memory/addressof.hpp"
#include "based/trait/is/invocable.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove/cvref.hpp"
#include "based/utility/declvar.hpp"
#include "based/utility/forward.hpp"

namespace based
{

namespace detail
{

// clang-format off

template<class T> constexpr T& fun(T& tmp) noexcept { return tmp; }
template<class T> void fun(T&&) = delete;

// clang-format on
}  // namespace detail

template<class T>
class reference_wrapper
{
public:
  // types
  using type = T;

  // construct/copy/destroy
  template<class U>
    requires(requires {
      detail::fun<T>(declval<U>());
      requires(!is_same_v<reference_wrapper, remove_cvref_t<U>>);
    })

  // NOLINTNEXTLINE(*explicit*)
  constexpr reference_wrapper(U&& obj
  ) noexcept(noexcept(detail::fun<T>(based::forward<U>(obj))))
      : m_ptr(addressof(detail::fun<T>(based::forward<U>(obj))))
  {
  }

  reference_wrapper(const reference_wrapper&) noexcept = default;
  reference_wrapper& operator=(const reference_wrapper& x) noexcept = default;

  reference_wrapper(reference_wrapper&&) noexcept = delete;
  reference_wrapper& operator=(reference_wrapper&& x) noexcept = delete;

  ~reference_wrapper() = default;

  // NOLINTBEGIN(*explicit*)
  constexpr operator T&() const noexcept { return *m_ptr; }
  constexpr T& get() const noexcept { return *m_ptr; }
  // NOLINTEND(*explicit*)

  template<class... Args>
  constexpr decltype(auto) operator()(Args&&... args) const
      noexcept(is_nothrow_invocable_v<T&, Args...>)
  {
    return get(based::forward<Args>(args)...);
  }

private:
  T* m_ptr;
};

// deduction guides
template<class T>
reference_wrapper(T&) -> reference_wrapper<T>;

}  // namespace based
