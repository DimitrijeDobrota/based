#pragma once

#include "based/integral/types.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
// clang-format off

template<class T>
struct RemoveExtent { using type = T; };
 
template<class T>
struct RemoveExtent<T[]> { using type = T; };
 
template<class T, size_t n>
struct RemoveExtent<T[n]> { using type = T; };


template<class T> using remove_extent_t = RemoveExtent<T>::type;

// NOLINTEND(*array*)
// clang-format on

}  // namespace based
