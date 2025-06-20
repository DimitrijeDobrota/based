#pragma once

#include "based/integral/types.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
// clang-format off

template<class T>
struct RemoveExtent { using Type = T; };
 
template<class T>
struct RemoveExtent<T[]> { using Type = T; };
 
template<class T, SizeT n>
struct RemoveExtent<T[n]> { using Type = T; };


template<class T> using RemoveExtentT = RemoveExtent<T>::Type;

// NOLINTEND(*array*)
// clang-format on

}  // namespace based
