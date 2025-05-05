#pragma once

namespace based
{

// clang-format off

template<class T> struct remove_pointer                    { using type = T; };
template<class T> struct remove_pointer<T*>                { using type = T; };
template<class T> struct remove_pointer<T* const>          { using type = T; };
template<class T> struct remove_pointer<T* volatile>       { using type = T; };
template<class T> struct remove_pointer<T* const volatile> { using type = T; };

template<class T> using remove_pointer_t = typename remove_pointer<T>::type;

// clang-format on

}  // namespace based
