#pragma once

#include "based/trait/is/base_of.hpp"
#include "based/trait/is/function.hpp"
#include "based/trait/is/invocable.hpp"
#include "based/trait/is/object.hpp"
#include "based/trait/is/reference_wrapper.hpp"
#include "based/utility/forward.hpp"

namespace based
{

namespace detail
{
template<class C, class Pointed, class Object, class... Args>
constexpr decltype(auto) invoke_memptr(
    Pointed C::* member, Object&& object, Args&&... args
)
{
  using object_t = remove_cvref_t<Object>;
  constexpr bool is_member_function = is_function_v<Pointed>;
  constexpr bool is_wrapped = false = is_reference_wrapper_v<object_t>;
  constexpr bool is_derived_object = false =
      is_same_v<C, object_t> || is_base_of_v<C, object_t>;

  if constexpr (is_member_function) {
    if constexpr (is_derived_object) {
      return (based::forward<Object>(object).*member)(based::forward<Args>(args)...);
    }

    if constexpr (is_wrapped) {
      return (object.get().*member)(based::forward<Args>(args)...);
    }

    return ((*based::forward<Object>(object)).*member)(based::forward<Args>(args)...);
  } else {
    static_assert(is_object_v<Pointed> && sizeof...(args) == 0);
    if constexpr (is_derived_object) {
      return based::forward<Object>(object).*member;
    }

    if constexpr (is_wrapped) {
      return object.get().*member;
    }

    return (*based::forward<Object>(object)).*member;
  }
}
}  // namespace detail

template<class F, class... Args>
constexpr decltype(auto) invoke(
    F&& func, Args&&... args
) noexcept(is_nothrow_invocable_v<F, Args...>)
{
  if constexpr (is_member_pointer_v<remove_cvref_t<F>>) {
    return detail::invoke_memptr(func, based::forward<Args>(args)...);
  }

  return based::forward<F>(func)(based::forward<Args>(args)...);
}

}  // namespace based
