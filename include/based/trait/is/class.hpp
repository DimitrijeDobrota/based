#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/union.hpp"

namespace based
{

namespace detail
{

template<class T>
bool_constant<!is_union_v<T>> test(int T::*);

template<class T>
false_type test(...);

}  // namespace detail

template<class T>
struct is_class : decltype(detail::test<T>(nullptr))
{
};

template<class T>
constexpr bool is_class_v = is_class<T>::value;

}  // namespace based
