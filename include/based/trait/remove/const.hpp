#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveConst          { using Type = T; };
template<class T> struct RemoveConst<const T> { using Type = T; };

template<class T> using RemoveConstT = typename RemoveConst<T>::Type;

// clang-format on

}  // namespace based
