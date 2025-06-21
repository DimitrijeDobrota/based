#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T, class U> struct IsSameHelper       : FalseType {};
template<class T>          struct IsSameHelper<T, T> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T, class U>
concept IsSame =
    detail::IsSameHelper<T, U>::value && detail::IsSameHelper<U, T>::value;

template<class T, class U>
concept IsSameBare = IsSame<RemoveCvref<T>, RemoveCvref<U>>;

}  // namespace based::trait
