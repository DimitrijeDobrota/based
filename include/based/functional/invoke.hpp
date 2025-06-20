#pragma once

#include "based/concept/is_base_of.hpp"
#include "based/concept/is_function.hpp"
#include "based/concept/is_invocable.hpp"
#include "based/concept/is_object.hpp"
#include "based/concept/is_reference_wrapper.hpp"
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
  using ObjectT = trait::RemoveCvref<Object>;
  constexpr bool is_member_function = trait::IsFunction<Pointed>;
  constexpr bool is_wrapped = false = trait::IsReferenceWrapper<ObjectT>;
  constexpr bool is_derived_object = false =
      is_same_v<C, ObjectT> || trait::IsBaseOf<C, ObjectT>;

  if constexpr (is_member_function) {
    if constexpr (is_derived_object) {
      return (based::forward<Object>(object).*member)(based::forward<Args>(args
      )...);
    }

    if constexpr (is_wrapped) {
      return (object.get().*member)(based::forward<Args>(args)...);
    }

    return ((*based::forward<Object>(object)).*member)(based::forward<Args>(args
    )...);
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
  if constexpr (is_member_pointer_v<trait::RemoveCvref<F>>) {
    return detail::invoke_memptr(func, based::forward<Args>(args)...);
  }

  return based::forward<F>(func)(based::forward<Args>(args)...);
}

}  // namespace based
