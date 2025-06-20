#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsPointer                    : FalseType {};
template<class T> struct IsPointer<T*>                : TrueType  {};
template<class T> struct IsPointer<T* const>          : TrueType  {};
template<class T> struct IsPointer<T* volatile>       : TrueType  {};
template<class T> struct IsPointer<T* const volatile> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsPointer = detail::IsPointer<T>::value;

}  // namespace based::trait
