#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsLValueRefeHelper     : FalseType {};
template<class T> struct IsLValueRefeHelper<T&> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsLValueRef = detail::IsLValueRefeHelper<T>::value;

}  // namespace based::trait
