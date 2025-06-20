#pragma once

#include "based/integral/types.hpp"
#include "based/trait/integral_constant.hpp"

namespace based
{

// NOLINTBEGIN(*array*)
template<class T>
struct IsArray : FalseType
{
};

template<class T>
struct IsArray<T[]> : TrueType
{
};

template<class T, SizeT n>
struct IsArray<T[n]> : TrueType
{
};
// NOLINTEND(*array*)

template<class T>
constexpr bool is_array_v = IsArray<T>::value;

}  // namespace based
