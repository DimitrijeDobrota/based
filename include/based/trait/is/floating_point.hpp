#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

template<class T>
struct is_floating_point : false_type
{
};

template<class T>
  requires(is_same_v<float, remove_cv_t<T>> || is_same_v<double, remove_cv_t<T>> || is_same_v<long double, remove_cv_t<T>>)
struct is_floating_point<T> : true_type
{
};

template<class T>
constexpr bool is_floating_point_v = is_floating_point<T>::value;

}  // namespace based
