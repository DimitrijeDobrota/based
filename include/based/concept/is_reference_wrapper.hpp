#pragma once

#include "based/functional/reference_wrapper.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsReferenceWrapper                      : FalseType {};
template<class U> struct IsReferenceWrapper<ReferenceWrapper<U>> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsReferenceWrapper = detail::IsReferenceWrapper<T>::value;

}  // namespace based::trait
