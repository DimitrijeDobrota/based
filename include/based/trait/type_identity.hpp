#pragma once

namespace based
{

// clang-format off

template<class T> struct TypeIdentity { using Type = T; };

template<class T> using TypeDentityT = TypeIdentity<T>::Type;

// clang-format on

}  // namespace based
