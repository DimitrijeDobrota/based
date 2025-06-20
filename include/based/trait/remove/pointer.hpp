#pragma once

namespace based
{

// clang-format off

template<class T> struct RemovePointer                    { using type = T; };
template<class T> struct RemovePointer<T*>                { using type = T; };
template<class T> struct RemovePointer<T* const>          { using type = T; };
template<class T> struct RemovePointer<T* volatile>       { using type = T; };
template<class T> struct RemovePointer<T* const volatile> { using type = T; };

template<class T> using remove_pointer_t = typename RemovePointer<T>::type;

// clang-format on

}  // namespace based
