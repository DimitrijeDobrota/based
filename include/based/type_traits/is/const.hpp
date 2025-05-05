#pragma once

#include "based/type_traits/integral_constant.hpp"

namespace based
{

// clang-format off

template<class T> struct is_const          : false_type {};
template<class T> struct is_const<const T> : true_type  {};

template<class T> constexpr bool is_const_v = is_const<T>::value;

// clang-format on

}  // namespace based
