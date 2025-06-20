#pragma once

namespace based
{

// clang-format off

template<class T> struct RemoveReference      { using type = T; };
template<class T> struct RemoveReference<T&>  { using type = T; };
template<class T> struct RemoveReference<T&&> { using type = T; };

template<class T> using remove_reference_t = typename RemoveReference<T>::type;

// clang-format on

}  // namespace based
