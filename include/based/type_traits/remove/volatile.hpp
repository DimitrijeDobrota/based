#pragma once

namespace based
{

// clang-format off

template<class T> struct remove_volatile             { using type = T; };
template<class T> struct remove_volatile<volatile T> { using type = T; };

template<class T> using remove_volatile_t = typename remove_volatile<T>::type;

// clang-format on

}  // namespace based
