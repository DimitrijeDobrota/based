#pragma once

#include "based/trait/remove/reference.hpp"
#include "based/trait/type_identity.hpp"

namespace based
{

// clang-format off

namespace detail
{

template<class T> TypeIdentity<remove_reference_t<T>*> try_add_pointer(int);
template<class T> TypeIdentity<T> try_add_pointer(...);

}  // namespace detail

template<class T> struct AddPointer : decltype(detail::try_add_pointer<T>(0)) {};

template<class T> using add_pointer_t = AddPointer<T>::type;

// clang-format on

}  // namespace based
