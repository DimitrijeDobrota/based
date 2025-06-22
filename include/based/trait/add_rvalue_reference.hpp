#pragma once

#include "based/trait/type_identity.hpp"

namespace based::trait
{

namespace detail
{

// Note that “cv void&&” is a substitution failure
template<class T>
auto try_add(int) -> TypeIdentity<T&&>;

// Handle T = cv void case
template<class T>
auto try_add(...) -> TypeIdentity<T>;

template<class T>
struct AddRValueReferenceHelper : decltype(detail::try_add<T>(0))
{
};

}  // namespace detail

template<class T>
using AddRValueReference = typename detail::AddRValueReferenceHelper<T>::Type;

}  // namespace based::trait
