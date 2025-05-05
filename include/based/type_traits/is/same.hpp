#pragma once

#include "based/type_traits/integral_constant.hpp"

namespace based
{

// clang-format off

template<class T, class U> struct is_same       : false_type {};
template<class T>          struct is_same<T, T> : true_type  {};

template<class T, class U> constexpr bool is_same_v = is_same<T, U>::value;

// clang-format on

}  // namespace based
