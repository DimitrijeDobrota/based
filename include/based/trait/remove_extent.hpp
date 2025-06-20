#pragma once

#include "based/integral/types.hpp"

namespace based::trait
{

namespace detail
{

// NOLINTBEGIN(*array*)
// clang-format off
template<class T>          struct RemoveExtent       { using Type = T; };
template<class T>          struct RemoveExtent<T[]>  { using Type = T; };
template<class T, SizeT n> struct RemoveExtent<T[n]> { using Type = T; };
// NOLINTEND(*array*)
// clang-format on

}  // namespace detail

template<class T>
using RemoveExtent = typename detail::RemoveExtent<T>::Type;

}  // namespace based::trait
