#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsLvalueReference     : FalseType {};
template<class T> struct IsLvalueReference<T&> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsLvalueReference = detail::IsLvalueReference<T>::value;

}  // namespace based::trait
