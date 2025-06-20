#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/integral/types.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
template<class T>
struct IsArray : false_type
{
};

template<class T>
struct IsArray<T[]> : true_type
{
};

template<class T, size_t n>
struct IsArray<T[n]> : true_type
{
};
// NOLINTEND(*array*)

template<class T>
constexpr bool is_array_v = IsArray<T>::value;

}  // namespace based
