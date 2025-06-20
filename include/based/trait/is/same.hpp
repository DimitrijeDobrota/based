#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T, class U>
struct IsSame : FalseType
{
};

template<class T>
struct IsSame<T, T> : TrueType
{
};

template<class T, class U>
constexpr bool is_same_v = IsSame<T, U>::value;

}  // namespace based
