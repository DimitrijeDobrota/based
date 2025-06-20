#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemovePointer                    { using Type = T; };
template<class T> struct RemovePointer<T*>                { using Type = T; };
template<class T> struct RemovePointer<T* const>          { using Type = T; };
template<class T> struct RemovePointer<T* volatile>       { using Type = T; };
template<class T> struct RemovePointer<T* const volatile> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemovePointer = typename detail::RemovePointer<T>::Type;

}  // namespace based::trait
