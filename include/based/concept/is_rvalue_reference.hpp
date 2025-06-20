#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsRvalueReference      : FalseType {};
template<class T> struct IsRvalueReference<T&&> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsRvalueReference = detail::IsRvalueReference<T>::value;

}  // namespace based::trait
