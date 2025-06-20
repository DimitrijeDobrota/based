#pragma once

#include "based/concept/is_invocable.hpp"
#include "based/concept/is_same.hpp"
#include "based/memory/addressof.hpp"
#include "based/trait/remove_cvref.hpp"
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
class ReferenceWrapper
{
public:
  // types
  using Type = T;

  // construct/copy/destroy
  template<class U>
    requires(requires {
      detail::fun<T>(declval<U>());
      requires(!trait::IsSame<ReferenceWrapper, trait::RemoveCvref<U>>);
    })

  // NOLINTNEXTLINE(*explicit*)
  constexpr ReferenceWrapper(U&& obj
  ) noexcept(noexcept(detail::fun<T>(based::forward<U>(obj))))
      : m_ptr(addressof(detail::fun<T>(based::forward<U>(obj))))
  {
  }

  ReferenceWrapper(const ReferenceWrapper&) noexcept = default;
  ReferenceWrapper& operator=(const ReferenceWrapper& x) noexcept = default;

  ReferenceWrapper(ReferenceWrapper&&) noexcept = delete;
  ReferenceWrapper& operator=(ReferenceWrapper&& x) noexcept = delete;

  ~ReferenceWrapper() = default;

  // NOLINTBEGIN(*explicit*)
  constexpr operator T&() const noexcept { return *m_ptr; }
  constexpr T& get() const noexcept { return *m_ptr; }
  // NOLINTEND(*explicit*)

  template<class... Args>
  constexpr decltype(auto) operator()(Args&&... args) const
      noexcept(trait::IsNothrowInvocable<T&, Args...>)
  {
    return get(based::forward<Args>(args)...);
  }

private:
  T* m_ptr;
};

// deduction guides
template<class T>
ReferenceWrapper(T&) -> ReferenceWrapper<T>;

}  // namespace based
