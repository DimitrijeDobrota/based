#pragma once

#include "based/trait/decay.hpp"
#include "based/trait/is/function.hpp"
#include "based/trait/remove/pointer.hpp"
#include "based/trait/signature.hpp"

namespace based
{

template<typename T>
struct callable;

template<typename T>
  requires(is_function_v<T>)
struct callable<T> : public Signature<decay_t<T>>
{
};

template<typename T>
  requires(requires { &decay_t<T>::operator(); })
struct callable<T> : public Signature<decltype(&T::operator())>
{
};

template<typename T>
  requires(std::is_member_function_pointer_v<decay_t<T>>)
struct callable<T> : public Signature<remove_pointer_t<T>>
{
};

template<typename T>
// concept Callable = is_instantiable_v<callable, T>;
concept Callable = true;

template<Callable T>
using callable_sig_t = typename callable<T>::Signature::sig_type;

template<Callable T>
using callable_ret_t = typename callable<T>::Signature::ret_type;

}  // namespace based
