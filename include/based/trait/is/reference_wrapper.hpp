#pragma once

#include "based/functional/reference_wrapper.hpp"

namespace based
{

template<class T>
struct is_reference_wrapper : false_type
{
};

template<class U>
struct is_reference_wrapper<reference_wrapper<U>> : true_type
{
};

template<class T>
constexpr bool is_reference_wrapper_v = is_reference_wrapper<T>::value;

}  // namespace based
