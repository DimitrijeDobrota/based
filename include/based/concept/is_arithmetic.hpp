#pragma once

#include "based/concept/is_floating_point.hpp"
#include "based/concept/is_integral.hpp"

namespace based::trait
{

template<class T>
concept IsArithmetic = IsIntegral<T> || IsFloatingPoint<T>;

}  // namespace based::trait
