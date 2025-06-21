#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsConstHelper          : FalseType {};
template<class T> struct IsConstHelper<const T> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsConst = detail::IsConstHelper<T>::value;

}  // namespace based::trait
