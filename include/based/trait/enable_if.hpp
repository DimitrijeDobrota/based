#pragma once

namespace based
{

// clang-format off

template<bool b, class T = void> struct EnableIf          {};
template<class T>                struct EnableIf<true, T> { using Type = T; };

template<bool b, class T = void> using EnableIfT = typename EnableIf<b, T>::type;

// clang-format on

}  // namespace based
