#pragma once

#include "based/trait/remove/reference.hpp"
#include "based/trait/type_identity.hpp"

namespace based
{

// clang-format off

namespace detail
{

template<class T> type_identity<remove_reference_t<T>*> try_add_pointer(int);
template<class T> type_identity<T> try_add_pointer(...);

}  // namespace detail

template<class T> struct add_pointer : decltype(detail::try_add_pointer<T>(0)) {};

template<class T> using add_pointer_t = add_pointer<T>::type;

// clang-format on

}  // namespace based
