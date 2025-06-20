#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsLvalueReference : false_type
{
};

template<class T>
struct IsLvalueReference<T&> : true_type
{
};

template<class T>
constexpr bool is_lvalue_reference_v = IsLvalueReference<T>::value;

}  // namespace based
