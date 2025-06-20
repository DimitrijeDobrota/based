#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemoveReference      { using Type = T; };
template<class T> struct RemoveReference<T&>  { using Type = T; };
template<class T> struct RemoveReference<T&&> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemoveReference = typename detail::RemoveReference<T>::Type;

}  // namespace based::trait
