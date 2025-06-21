#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemoveVolatileHelper             { using Type = T; };
template<class T> struct RemoveVolatileHelper<volatile T> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemoveVolatile = typename detail::RemoveVolatileHelper<T>::Type;

}  // namespace based::trait
