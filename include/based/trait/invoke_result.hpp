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
struct InvokeImpl
{
  template<class F, class... Args>
  static auto call(F&& func, Args&&... args)
      -> decltype(based::forward<F>(func)(based::forward<Args>(args)...));
};

template<class B, class MT>
struct InvokeImpl<MT B::*>
{
  template<class T>
    requires(is_base_of_v<B, DecayT<T>>)
  static auto get(T&& obj) -> T&&;

  template<class T>
    requires(is_reference_wrapper_v<DecayT<T>>)
  static auto get(T&& obj) -> decltype(obj.get());

  template<class T>
    requires(!is_base_of_v<B, DecayT<T>> && !is_reference_wrapper_v<DecayT<T>>)
  static auto get(T&& obj) -> decltype(*based::forward<T>(obj));

  template<class T, class... Args, class MT1>
    requires(is_function_v<MT1>)
  static auto call(MT1 B::* pmf, T&& obj, Args&&... args)
      -> decltype((InvokeImpl::get(based::forward<T>(obj)).*pmf)(
          based::forward<Args>(args)...
      ));

  template<class T>
  static auto call(MT B::* pmd, T&& obj)
      -> decltype(InvokeImpl::get(based::forward<T>(obj)).*pmd);
};

template<class F, class... Args>
auto invoke_f(F&& func, Args&&... args) -> decltype(InvokeImpl<DecayT<F>>::call(
    based::forward<F>(func), based::forward<Args>(args)...
));

}  // namespace detail

namespace detail
{

template<typename AlwaysVoid, typename, typename...>
struct InvokeResult
{
};

template<typename F, typename... Args>
struct InvokeResult<
    decltype(void(detail::invoke_f(declval<F>(), declval<Args>()...))),
    F,
    Args...>
{
  using Type = decltype(detail::invoke_f(declval<F>(), declval<Args>()...));
};

}  // namespace detail

template<class F, class... Args>
struct InvokeResult : detail::InvokeResult<void, F, Args...>
{
};

template<class F, class... Args>
using InvokeResultT = typename InvokeResult<F, Args...>::Type;

}  // namespace based
