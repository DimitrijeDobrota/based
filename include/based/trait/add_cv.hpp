#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct AddCVHelper { using Type = const volatile T; };
// clang-format on

}  // namespace detail

template<class T>
using AddCV = typename detail::AddCVHelper<T>::Type;

}  // namespace based::trait
