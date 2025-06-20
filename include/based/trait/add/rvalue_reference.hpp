#pragma once

#include "based/trait/type_identity.hpp"

namespace based
{

// clang-format off

namespace detail
{

// Note that “cv void&&” is a substitution failure
template<class T> auto try_add(int) -> TypeIdentity<T&&>;

// Handle T = cv void case
template<class T> auto try_add(...) -> TypeIdentity<T>;

}  // namespace detail

template<class T> struct AddRvalueReference : decltype(detail::try_add<T>(0)) {};

template<class T> using AddRvalueReferenceT = AddRvalueReference<T>::Type;

// clang-format on

}  // namespace based
