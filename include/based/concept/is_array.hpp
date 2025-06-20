#pragma once

#include "based/integral/types.hpp"
#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
// NOLINTBEGIN(*array*)
template<class T>          struct IsArray       : FalseType {};
template<class T>          struct IsArray<T[]>  : TrueType  {};
template<class T, SizeT n> struct IsArray<T[n]> : TrueType  {};
// NOLINTEND(*array*)
// clang-format on

}  // namespace detail

template<class T>
concept IsArray = detail::IsArray<T>::value;

}  // namespace based::trait
