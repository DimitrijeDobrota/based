#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsConst : FalseType
{
};

template<class T>
struct IsConst<const T> : TrueType
{
};

template<class T>
constexpr bool is_const_v = IsConst<T>::value;

}  // namespace based
