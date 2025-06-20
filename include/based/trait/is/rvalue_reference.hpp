#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsRvalueReference : FalseType
{
};

template<class T>
struct IsRvalueReference<T&&> : TrueType
{
};

template<class T>
constexpr bool is_rvalue_reference_v = IsRvalueReference<T>::value;

}  // namespace based
