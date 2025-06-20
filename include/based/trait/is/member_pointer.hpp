#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

namespace detail
{

template<class T>
struct IsMemberPointerHelper : false_type { };

template<class T, class U>
struct IsMemberPointerHelper<T U::*> : true_type
{
};

}  // namespace detail

template<class T>
struct IsMemberPointer : detail::IsMemberPointerHelper<remove_cv_t<T>>
{
};

template<class T>
constexpr bool is_member_pointer_v = IsMemberPointer<T>::value;

}  // namespace based
