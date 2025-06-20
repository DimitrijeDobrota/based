#pragma once

namespace based
{

// clang-format off

template<class T> struct RemovePointer                    { using Type = T; };
template<class T> struct RemovePointer<T*>                { using Type = T; };
template<class T> struct RemovePointer<T* const>          { using Type = T; };
template<class T> struct RemovePointer<T* volatile>       { using Type = T; };
template<class T> struct RemovePointer<T* const volatile> { using Type = T; };

template<class T> using RemovePointerT = typename RemovePointer<T>::Type;

// clang-format on

}  // namespace based
