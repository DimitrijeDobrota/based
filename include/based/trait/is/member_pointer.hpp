#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

namespace detail
{

template<class T>
struct is_member_pointer_helper : false_type
{
};

template<class T, class U>
struct is_member_pointer_helper<T U::*> : true_type
{
};

}  // namespace detail

template<class T>
struct is_member_pointer : detail::is_member_pointer_helper<remove_cv_t<T>>
{
};

template<class T>
constexpr bool is_member_pointer_v = is_member_pointer<T>::value;

}  // namespace based
