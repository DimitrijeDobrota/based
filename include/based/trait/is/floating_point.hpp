#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove_cv.hpp"

namespace based
{

template<class T>
struct IsFloatingPoint : FalseType
{
};

template<class T>
  requires(is_same_v<float, trait::RemoveCv<T>> || is_same_v<double, trait::RemoveCv<T>> || is_same_v<long double, trait::RemoveCv<T>>)
struct IsFloatingPoint<T> : TrueType
{
};

template<class T>
constexpr bool is_floating_point_v = IsFloatingPoint<T>::value;

}  // namespace based
