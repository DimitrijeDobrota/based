#pragma once

#include "based/trait/decay.hpp"
#include "based/trait/is/function.hpp"
#include "based/trait/remove_pointer.hpp"
#include "based/trait/signature.hpp"

namespace based
{

template<typename T>
struct callable;

template<typename T>
  requires(is_function_v<T>)
struct callable<T> : public Signature<trait::Decay<T>>
{
};

template<typename T>
  requires(requires { &trait::Decay<T>::operator(); })
struct callable<T> : public Signature<decltype(&T::operator())>
{
};

template<typename T>
  requires(std::is_member_function_pointer_v<trait::Decay<T>>)
struct callable<T> : public Signature<trait::RemovePointer<T>>
{
};

template<typename T>
// concept Callable = is_instantiable_v<callable, T>;
concept Callable = true;

template<Callable T>
using CallableSigT = typename callable<T>::Signature::SigType;

template<Callable T>
using CallableRetT = typename callable<T>::Signature::RetType;

}  // namespace based
