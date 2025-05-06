#pragma once

namespace based
{

// clang-format off

template<class T> struct remove_cv                   { using type = T; };
template<class T> struct remove_cv<const T>          { using type = T; };
template<class T> struct remove_cv<volatile T>       { using type = T; };
template<class T> struct remove_cv<const volatile T> { using type = T; };

template<class T> using remove_cv_t = typename remove_cv<T>::type;

// clang-format on

}  // namespace based
