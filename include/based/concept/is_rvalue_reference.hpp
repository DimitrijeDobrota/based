#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsRValueRefHelper      : FalseType {};
template<class T> struct IsRValueRefHelper<T&&> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsRValueRef = detail::IsRValueRefHelper<T>::value;

}  // namespace based::trait
