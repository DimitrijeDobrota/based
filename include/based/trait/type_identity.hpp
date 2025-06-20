#pragma once

namespace based
{

// clang-format off

template<class T> struct TypeIdentity { using type = T; };

template<class T> using type_dentity_t = TypeIdentity<T>::type;

// clang-format on

}  // namespace based
