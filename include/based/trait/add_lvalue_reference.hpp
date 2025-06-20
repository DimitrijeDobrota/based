#pragma once

#include "based/trait/type_identity.hpp"

namespace based::trait
{

namespace detail
{

template<class T>  // Note that “cv void&” is a substitution failure
auto try_add(int) -> TypeIdentity<T&>;

template<class T>  // Handle T = cv void case
auto try_add(...) -> TypeIdentity<T>;

template<class T>
struct AddLvalueReference : decltype(detail::try_add<T>(0))
{
};

}  // namespace detail

template<class T>
using AddLvalueReference = detail::AddLvalueReference<T>::Type;

}  // namespace based::trait
