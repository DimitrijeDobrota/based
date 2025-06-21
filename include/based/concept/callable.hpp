#pragma once

#include "based/concept/is_function.hpp"
#include "based/trait/decay.hpp"
#include "based/trait/remove_pointer.hpp"
#include "based/trait/signature.hpp"

namespace based::trait
{

template<class T>
struct IsCallableHelper;

template<class T>
  requires(IsFunction<T>)
struct IsCallableHelper<T> : public Signature<Decay<T>>
{
};

template<class T>
  requires(requires { &Decay<T>::operator(); })
struct IsCallableHelper<T> : public Signature<decltype(&T::operator())>
{
};

template<class T>
  requires(std::is_member_function_pointer_v<Decay<T>>)
struct IsCallableHelper<T> : public Signature<RemovePointer<T>>
{
};

template<class T>
// concept Callable = is_instantiable_v<callable, T>;
concept IsCallable = true;

template<IsCallable T>
using CallableSigT = typename IsCallableHelper<T>::Signature::SigType;

template<IsCallable T>
using CallableRetT = typename IsCallableHelper<T>::Signature::RetType;

}  // namespace based::trait
