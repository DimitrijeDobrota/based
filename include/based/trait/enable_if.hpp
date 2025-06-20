#pragma once

namespace based
{

// clang-format off

template<bool b, class T = void> struct EnableIf          {};
template<class T>                struct EnableIf<true, T> { using type = T; };

template<bool b, class T = void> using enable_if_t = typename EnableIf<b, T>::type;

// clang-format on

}  // namespace based
