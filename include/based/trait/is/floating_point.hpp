#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

template<class T>
struct IsFloatingPoint : false_type
{
};

template<class T>
  requires(is_same_v<float, remove_cv_t<T>> || is_same_v<double, remove_cv_t<T>> || is_same_v<long double, remove_cv_t<T>>)
struct IsFloatingPoint<T> : true_type
{
};

template<class T>
constexpr bool is_floating_point_v = IsFloatingPoint<T>::value;

}  // namespace based
