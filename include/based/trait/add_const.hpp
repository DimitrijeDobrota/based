#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct AddConstHelper { using Type = const T; };
// clang-format on

}  // namespace detail

template<class T>
using AddConst = typename detail::AddConstHelper<T>::Type;

}  // namespace based::trait
