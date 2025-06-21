#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsPointerHelper                    : FalseType {};
template<class T> struct IsPointerHelper<T*>                : TrueType  {};
template<class T> struct IsPointerHelper<T* const>          : TrueType  {};
template<class T> struct IsPointerHelper<T* volatile>       : TrueType  {};
template<class T> struct IsPointerHelper<T* const volatile> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsPointer = detail::IsPointerHelper<T>::value;

}  // namespace based::trait
