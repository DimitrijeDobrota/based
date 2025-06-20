#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveCv                   { using type = T; };
template<class T> struct RemoveCv<const T>          { using type = T; };
template<class T> struct RemoveCv<volatile T>       { using type = T; };
template<class T> struct RemoveCv<const volatile T> { using type = T; };

template<class T> using remove_cv_t = typename RemoveCv<T>::type;

// clang-format on

}  // namespace based
