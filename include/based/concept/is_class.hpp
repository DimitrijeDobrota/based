#pragma once

#include "based/concept/is_union.hpp"
#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

template<class T>
  requires(!IsUnion<T>)
auto test(int T::*) -> TrueType;

template<class T>
auto test(...) -> FalseType;

}  // namespace detail

template<class T>
concept IsClass = decltype(detail::test<T>(nullptr))::value;

}  // namespace based::trait
