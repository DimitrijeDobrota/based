#pragma once

#include "based/concept/is_base_of.hpp"
#include "based/concept/is_reference_wrapper.hpp"
#include "based/trait/decay.hpp"
#include "based/utility/forward.hpp"

namespace based::trait
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
    requires(trait::IsBaseOf<B, trait::Decay<T>>)
  static auto get(T&& obj) -> T&&;

  template<class T>
    requires(trait::IsRefWrapper<trait::Decay<T>>)
  static auto get(T&& obj) -> decltype(obj.get());

  template<class T>
    requires(!trait::IsBaseOf<B, trait::Decay<T>> && !trait::IsRefWrapper<trait::Decay<T>>)
  static auto get(T&& obj) -> decltype(*based::forward<T>(obj));

  template<class T, class... Args, class MT1>
    requires(trait::IsFunction<MT1>)
  static auto call(MT1 B::* pmf, T&& obj, Args&&... args)
      -> decltype((InvokeImpl::get(based::forward<T>(obj)).*pmf)(
          based::forward<Args>(args)...
      ));

  template<class T>
  static auto call(MT B::* pmd, T&& obj)
      -> decltype(InvokeImpl::get(based::forward<T>(obj)).*pmd);
};

template<class F, class... Args>
auto invoke_f(F&& func, Args&&... args)
    -> decltype(InvokeImpl<trait::Decay<F>>::call(
        based::forward<F>(func), based::forward<Args>(args)...
    ));

}  // namespace detail

namespace detail
{

template<typename AlwaysVoid, typename, typename...>
struct InvokeResultHelperHelper
{
};

template<typename F, typename... Args>
struct InvokeResultHelperHelper<
    decltype(void(detail::invoke_f(declval<F>(), declval<Args>()...))),
    F,
    Args...>
{
  using Type = decltype(detail::invoke_f(declval<F>(), declval<Args>()...));
};

template<class F, class... Args>
struct InvokeResultHelper : detail::InvokeResultHelperHelper<void, F, Args...>
{
};

}  // namespace detail

template<class F, class... Args>
using InvokeResult = typename detail::InvokeResultHelper<F, Args...>::Type;

}  // namespace based::trait
