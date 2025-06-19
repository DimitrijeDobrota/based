#pragma once

#include "based/trait/remove/pointer.hpp"
#include "based/trait/signature.hpp"

namespace based
{

template<typename T>
struct callable;

template<typename T>
  requires(std::is_function_v<T>)
struct callable<T> : public signature<std::decay_t<T>>
{
};

template<typename T>
  requires(requires { &std::decay_t<T>::operator(); })
struct callable<T> : public signature<decltype(&T::operator())>
{
};

template<typename T>
  requires(std::is_member_function_pointer_v<std::decay_t<T>>)
struct callable<T> : public signature<remove_pointer_t<T>>
{
};

template<typename T>
// concept Callable = is_instantiable_v<callable, T>;
concept Callable = true;

template<Callable T>
using callable_sig_t = typename callable<T>::signature::sig_type;

template<Callable T>
using callable_ret_t = typename callable<T>::signature::ret_type;

}  // namespace based
