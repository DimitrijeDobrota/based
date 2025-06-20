#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsPointer : false_type
{
};

template<class T>
struct IsPointer<T*> : true_type
{
};

template<class T>
struct IsPointer<T* const> : true_type
{
};

template<class T>
struct IsPointer<T* volatile> : true_type
{
};

template<class T>
struct IsPointer<T* const volatile> : true_type
{
};

template<class T>
constexpr bool is_pointer_v = IsPointer<T>::value;

}  // namespace based
