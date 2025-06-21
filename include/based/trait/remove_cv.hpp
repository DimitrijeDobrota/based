#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemoveCvHelper                   { using Type = T; };
template<class T> struct RemoveCvHelper<const T>          { using Type = T; };
template<class T> struct RemoveCvHelper<volatile T>       { using Type = T; };
template<class T> struct RemoveCvHelper<const volatile T> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemoveCv = typename detail::RemoveCvHelper<T>::Type;

}  // namespace based::trait
