#pragma once

#include "based/functional/reference_wrapper.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off
template<class T> struct IsRefWrapperHelper                : FalseType {};
template<class U> struct IsRefWrapperHelper<RefWrapper<U>> : TrueType  {};
// clang-format on

}  // namespace detail

template<class T>
concept IsRefWrapper = detail::IsRefWrapperHelper<T>::value;

}  // namespace based::trait
