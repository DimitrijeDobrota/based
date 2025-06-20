#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveCv                   { using Type = T; };
template<class T> struct RemoveCv<const T>          { using Type = T; };
template<class T> struct RemoveCv<volatile T>       { using Type = T; };
template<class T> struct RemoveCv<const volatile T> { using Type = T; };

template<class T> using RemoveCvT = typename RemoveCv<T>::Type;

// clang-format on

}  // namespace based
