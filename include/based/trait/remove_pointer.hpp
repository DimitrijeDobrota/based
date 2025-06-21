#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct RemovePointerHelper                    { using Type = T; };
template<class T> struct RemovePointerHelper<T*>                { using Type = T; };
template<class T> struct RemovePointerHelper<T* const>          { using Type = T; };
template<class T> struct RemovePointerHelper<T* volatile>       { using Type = T; };
template<class T> struct RemovePointerHelper<T* const volatile> { using Type = T; };
// clang-format on

}  // namespace detail

template<class T>
using RemovePointer = typename detail::RemovePointerHelper<T>::Type;

}  // namespace based::trait
