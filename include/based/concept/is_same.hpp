#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T, class U> struct IsSame       : FalseType {};
template<class T>          struct IsSame<T, T> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T, class U>
concept IsSame = detail::IsSame<T, U>::value && detail::IsSame<U, T>::value;

template<class T, class U>
concept IsSameBare = IsSame<RemoveCvref<T>, RemoveCvref<U>>;

}  // namespace based::trait
