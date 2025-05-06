#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

// clang-format off

template <class T> struct is_rvalue_reference      : false_type {};
template <class T> struct is_rvalue_reference<T&&> : true_type  {};

template <class T> constexpr bool is_rvalue_reference_v = is_rvalue_reference<T>::value;

// clang-format on

}  // namespace based
