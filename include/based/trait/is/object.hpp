#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/array.hpp"
#include "based/trait/is/class.hpp"
#include "based/trait/is/scalar.hpp"
#include "based/trait/is/union.hpp"

namespace based
{

template<class T>
struct IsObject : FalseType
{
};

template<class T>
  requires(is_scalar_v<T> || is_array_v<T> || is_union_v<T> || is_class_v<T>)
struct IsObject<T> : TrueType
{
};

template<class T>
constexpr bool is_object_v = IsObject<T>::value;

}  // namespace based
