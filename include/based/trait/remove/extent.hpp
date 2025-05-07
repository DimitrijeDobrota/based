#pragma once

#include "based/types/types.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
// clang-format off

template<class T>
struct remove_extent { using type = T; };
 
template<class T>
struct remove_extent<T[]> { using type = T; };
 
template<class T, size_t n>
struct remove_extent<T[n]> { using type = T; };


template<class T> using remove_extent_t = remove_extent<T>::type;

// NOLINTEND(*array*)
// clang-format on

}  // namespace based
