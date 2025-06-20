#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveVolatile             { using type = T; };
template<class T> struct RemoveVolatile<volatile T> { using type = T; };

template<class T> using remove_volatile_t = typename RemoveVolatile<T>::type;

// clang-format on

}  // namespace based
