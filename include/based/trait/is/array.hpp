#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/integral/types.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
template<class T>
struct is_array : false_type
{
};

template<class T>
struct is_array<T[]> : true_type
{
};

template<class T, size_t n>
struct is_array<T[n]> : true_type
{
};
// NOLINTEND(*array*)

template<class T>
constexpr bool is_array_v = is_array<T>::value;

}  // namespace based
