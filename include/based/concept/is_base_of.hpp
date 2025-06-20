#pragma once

#include "based/concept/is_class.hpp"
#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

template<class B>
auto test_ptr_conv(const volatile B*) -> TrueType;

template<class>
auto test_ptr_conv(const volatile void*) -> FalseType;

template<class B, class D>
auto test_is_base_of(int)
    -> decltype(test_ptr_conv<B>(static_cast<D*>(nullptr)));

template<class, class>
auto test_is_base_of(...) -> TrueType;  // private or ambiguous base

}  // namespace detail

template<class Base, class Derived>
concept IsBaseOf = requires {
  requires(IsClass<Base>);
  requires(IsClass<Derived>);
  requires(decltype(detail::test_is_base_of<Base, Derived>(0))::value);
};

}  // namespace based::trait
