#pragma once

#include "based/integral/types.hpp"
#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
// NOLINTBEGIN(*array*)
template<class T>          struct IsArrayHelper       : FalseType {};
template<class T>          struct IsArrayHelper<T[]>  : TrueType  {};
template<class T, SizeT n> struct IsArrayHelper<T[n]> : TrueType  {};
// NOLINTEND(*array*)
// clang-format on

}  // namespace detail

template<class T>
concept IsArray = detail::IsArrayHelper<T>::value;

}  // namespace based::trait
