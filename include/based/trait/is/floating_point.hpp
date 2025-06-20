#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

template<class T>
struct IsFloatingPoint : FalseType
{
};

template<class T>
  requires(is_same_v<float, RemoveCvT<T>> || is_same_v<double, RemoveCvT<T>> || is_same_v<long double, RemoveCvT<T>>)
struct IsFloatingPoint<T> : TrueType
{
};

template<class T>
constexpr bool is_floating_point_v = IsFloatingPoint<T>::value;

}  // namespace based
