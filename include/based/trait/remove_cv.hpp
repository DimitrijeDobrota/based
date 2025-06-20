#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemoveCv                   { using Type = T; };
template<class T> struct RemoveCv<const T>          { using Type = T; };
template<class T> struct RemoveCv<volatile T>       { using Type = T; };
template<class T> struct RemoveCv<const volatile T> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemoveCv = typename detail::RemoveCv<T>::Type;

}  // namespace based::trait
