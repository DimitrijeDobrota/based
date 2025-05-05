#pragma once

namespace based
{

// clang-format off

template<class T> struct remove_const          { using type = T; };
template<class T> struct remove_const<const T> { using type = T; };

template<class T> using remove_const_t = typename remove_const<T>::type;

// clang-format on

}  // namespace based
