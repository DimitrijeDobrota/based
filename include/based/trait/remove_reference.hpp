#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemoveReferenceHelper      { using Type = T; };
template<class T> struct RemoveReferenceHelper<T&>  { using Type = T; };
template<class T> struct RemoveReferenceHelper<T&&> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemoveReference = typename detail::RemoveReferenceHelper<T>::Type;

}  // namespace based::trait
