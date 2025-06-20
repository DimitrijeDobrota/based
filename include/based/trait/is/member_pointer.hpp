#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

namespace detail
{

template<class T>
struct IsMemberPointerHelper : FalseType
{
};

template<class T, class U>
struct IsMemberPointerHelper<T U::*> : TrueType
{
};

}  // namespace detail

template<class T>
struct IsMemberPointer : detail::IsMemberPointerHelper<RemoveCvT<T>>
{
};

template<class T>
constexpr bool is_member_pointer_v = IsMemberPointer<T>::value;

}  // namespace based
