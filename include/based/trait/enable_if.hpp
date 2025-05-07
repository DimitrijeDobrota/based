#pragma once

namespace based
{

// clang-format off

template<bool b, class T = void> struct enable_if          {};
template<class T>                struct enable_if<true, T> { using type = T; };

template<bool b, class T = void> using enable_if_t = typename enable_if<b, T>::type;

// clang-format on

}  // namespace based
