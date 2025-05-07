#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/floating_point.hpp"
#include "based/trait/is/integral.hpp"

namespace based
{

template<class T>
struct is_arithmetic : bool_constant<is_integral_v<T> || is_floating_point_v<T>>
{
};

template<class T>
constexpr bool is_arithmetic_v = is_arithmetic<T>::value;

}  // namespace based
