#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/arithmetic.hpp"
#include "based/trait/is/enum.hpp"
#include "based/trait/is/member_pointer.hpp"
#include "based/trait/is/null_pointer.hpp"
#include "based/trait/is/pointer.hpp"

namespace based
{

template<class T>
struct IsScalar : false_type
{
};

template<class T>
  requires(is_arithmetic_v<T> || is_enum_v<T> || is_pointer_v<T> || is_member_pointer_v<T> || is_null_pointer_v<T>)
struct IsScalar<T>
{
};

template<class T>
constexpr bool is_scalar_v = IsScalar<T>::value;

}  // namespace based
