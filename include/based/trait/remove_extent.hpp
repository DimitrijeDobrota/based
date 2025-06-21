#pragma once

#include "based/integral/types.hpp"

namespace based::trait
{

namespace detail
{

// NOLINTBEGIN(*array*)
// clang-format off
template<class T>          struct RemoveExtentHelper       { using Type = T; };
template<class T>          struct RemoveExtentHelper<T[]>  { using Type = T; };
template<class T, SizeT n> struct RemoveExtentHelper<T[n]> { using Type = T; };
// NOLINTEND(*array*)
// clang-format on

}  // namespace detail

template<class T>
using RemoveExtent = typename detail::RemoveExtentHelper<T>::Type;

}  // namespace based::trait
