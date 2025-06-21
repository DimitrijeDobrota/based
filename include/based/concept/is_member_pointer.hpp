#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove_cv.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T>          struct IsMemberPointerHelper         : FalseType {};
template<class T, class U> struct IsMemberPointerHelper<T U::*> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsMemberPointer = detail::IsMemberPointerHelper<RemoveCv<T>>::value;

}  // namespace based::trait
