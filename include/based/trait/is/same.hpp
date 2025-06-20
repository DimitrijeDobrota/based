#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T, class U>
struct IsSame : false_type
{
};

template<class T>
struct IsSame<T, T> : true_type
{
};

template<class T, class U>
constexpr bool is_same_v = IsSame<T, U>::value;

}  // namespace based
