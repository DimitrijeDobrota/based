#pragma once

#include "based/concept/is_floating_point.hpp"
#include "based/concept/is_integral.hpp"
#include "based/trait/integral_constant.hpp"

namespace based::trait
{

template<class T>
concept IsArithmetic = IsIntegral<T> || IsFloatingPoint<T>;

}  // namespace based::trait
