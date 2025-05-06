#pragma once

namespace based
{

// clang-format off

template<class T> struct type_identity { using type = T; };

template<class T> using type_dentity_t = type_identity<T>::type;

// clang-format on

}  // namespace based
