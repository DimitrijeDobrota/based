#pragma once

#include "based/trait/type_identity.hpp"

namespace based
{

// clang-format off

namespace detail
{

// Note that “cv void&” is a substitution failure
template<class T> auto try_add(int) -> type_identity<T&>;

// Handle T = cv void case
template<class T> auto try_add(...) -> type_identity<T>;

}  // namespace detail

template<class T> struct add_lvalue_reference : decltype(detail::try_add<T>(0)) {};

template<class T> using add_lvalue_reference_t = add_lvalue_reference<T>::type;

// clang-format on

}  // namespace based
