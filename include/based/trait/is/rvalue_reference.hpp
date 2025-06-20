#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsRvalueReference : false_type
{
};

template<class T>
struct IsRvalueReference<T&&> : true_type
{
};

template<class T>
constexpr bool is_rvalue_reference_v = IsRvalueReference<T>::value;

}  // namespace based
