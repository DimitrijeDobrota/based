#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct TypeIdentity { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using TypeIdentity = detail::TypeIdentity<T>::Type;

}  // namespace based::trait
