#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveConst          { using type = T; };
template<class T> struct RemoveConst<const T> { using type = T; };

template<class T> using remove_const_t = typename RemoveConst<T>::type;

// clang-format on

}  // namespace based
