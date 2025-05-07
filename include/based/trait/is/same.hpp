#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T, class U>
struct is_same : false_type
{
};

template<class T>
struct is_same<T, T> : true_type
{
};

template<class T, class U>
constexpr bool is_same_v = is_same<T, U>::value;

}  // namespace based
