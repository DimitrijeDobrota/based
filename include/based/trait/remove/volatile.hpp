#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveVolatile             { using Type = T; };
template<class T> struct RemoveVolatile<volatile T> { using Type = T; };

template<class T> using RemoveVolatileT = typename RemoveVolatile<T>::Type;

// clang-format on

}  // namespace based
