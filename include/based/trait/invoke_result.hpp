#pragma once

#include "based/trait/decay.hpp"
#include "based/trait/is/base_of.hpp"
#include "based/trait/is/reference_wrapper.hpp"
#include "based/utility/forward.hpp"

namespace based
{

namespace detail
{

template<class T>
struct invoke_impl
{
  template<class F, class... Args>
  static auto call(F&& func, Args&&... args)
      -> decltype(based::forward<F>(func)(based::forward<Args>(args)...));
};

template<class B, class MT>
struct invoke_impl<MT B::*>
{
  template<class T>
    requires(is_base_of_v<B, decay_t<T>>)
  static auto get(T&& obj) -> T&&;

  template<class T>
    requires(is_reference_wrapper_v<decay_t<T>>)
  static auto get(T&& obj) -> decltype(obj.get());

  template<class T>
    requires(!is_base_of_v<B, decay_t<T>> && !is_reference_wrapper_v<decay<T>>)
  static auto get(T&& obj) -> decltype(*based::forward<T>(obj));

  template<class T, class... Args, class MT1>
    requires(is_function_v<MT1>)
  static auto call(MT1 B::* pmf, T&& obj, Args&&... args)
      -> decltype((invoke_impl::get(based::forward<T>(obj)).*pmf)(
          based::forward<Args>(args)...
      ));

  template<class T>
  static auto call(MT B::* pmd, T&& obj)
      -> decltype(invoke_impl::get(based::forward<T>(obj)).*pmd);
};

template<class F, class... Args>
auto INVOKE(F&& func, Args&&... args) -> decltype(invoke_impl<decay_t<F>>::call(
    based::forward<F>(func), based::forward<Args>(args)...
));

}  // namespace detail

namespace detail
{

template<typename AlwaysVoid, typename, typename...>
struct invoke_result
{
};

template<typename F, typename... Args>
struct invoke_result<
    decltype(void(detail::INVOKE(declval<F>(), declval<Args>()...))),
    F,
    Args...>
{
  using type = decltype(detail::INVOKE(declval<F>(), declval<Args>()...));
};

}  // namespace detail

template<class F, class... Args>
struct invoke_result : detail::invoke_result<void, F, Args...>
{
};

template<class F, class... Args>
using invoke_result_t = typename invoke_result<F, Args...>::type;

}  // namespace based
