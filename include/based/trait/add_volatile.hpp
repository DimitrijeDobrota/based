#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct AddVolatileHelper { using Type = volatile T; };
// clang-format on

}  // namespace detail

template<class T>
using AddVolatile = typename detail::AddVolatileHelper<T>::Type;

}  // namespace based::trait
