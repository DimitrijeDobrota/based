#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/array.hpp"
#include "based/trait/is/class.hpp"
#include "based/trait/is/scalar.hpp"
#include "based/trait/is/union.hpp"

namespace based
{

template<class T>
struct is_object : false_type
{
};

template<class T>
  requires(is_scalar_v<T> || is_array_v<T> || is_union_v<T> || is_class_v<T>)
struct is_object<T> : true_type
{
};

template<class T>
constexpr bool is_object_v = is_object<T>::value;

}  // namespace based
