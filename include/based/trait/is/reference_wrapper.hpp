#pragma once

#include "based/functional/reference_wrapper.hpp"

namespace based
{

template<class T>
struct IsReferenceWrapper : false_type
{
};

template<class U>
struct IsReferenceWrapper<ReferenceWrapper<U>> : true_type
{
};

template<class T>
constexpr bool is_reference_wrapper_v = IsReferenceWrapper<T>::value;

}  // namespace based
