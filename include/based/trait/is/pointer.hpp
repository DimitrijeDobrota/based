#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsPointer : FalseType
{
};

template<class T>
struct IsPointer<T*> : TrueType
{
};

template<class T>
struct IsPointer<T* const> : TrueType
{
};

template<class T>
struct IsPointer<T* volatile> : TrueType
{
};

template<class T>
struct IsPointer<T* const volatile> : TrueType
{
};

template<class T>
constexpr bool is_pointer_v = IsPointer<T>::value;

}  // namespace based
