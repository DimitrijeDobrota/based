#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct is_const : false_type
{
};

template<class T>
struct is_const<const T> : true_type
{
};

template<class T>
constexpr bool is_const_v = is_const<T>::value;

}  // namespace based
