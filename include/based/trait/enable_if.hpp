#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<bool b, class T = void> struct EnableIfHelper          {};
template<class T>                struct EnableIfHelper<true, T> { using Type = T; };
// clang-format on

}  // namespace detail

template<bool b, class T = void>
using EnableIfT = typename detail::EnableIfHelper<b, T>::type;

}  // namespace based::trait
