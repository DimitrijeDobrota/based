#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveReference      { using Type = T; };
template<class T> struct RemoveReference<T&>  { using Type = T; };
template<class T> struct RemoveReference<T&&> { using Type = T; };

template<class T> using RemoveReferenceT = typename RemoveReference<T>::Type;

// clang-format on

}  // namespace based
