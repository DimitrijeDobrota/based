#pragma once

#include "based/trait/integral_constant.hpp"
#include "based/trait/is/class.hpp"

namespace based
{

namespace details
{

template<class B>
true_type test_ptr_conv(const volatile B*);

template<class>
false_type test_ptr_conv(const volatile void*);

template<class B, class D>
auto test_is_base_of(int)
    -> decltype(test_ptr_conv<B>(static_cast<D*>(nullptr)));

template<class, class>
auto test_is_base_of(...) -> true_type;  // private or ambiguous base

}  // namespace details

template<class Base, class Derived>
struct IsBaseOf : false_type
{
};

template<class Base, class Derived>
  requires(
      is_class_v<Base> && is_class_v<Derived>
      && decltype(details::test_is_base_of<Base, Derived>(0))::value
  )
struct IsBaseOf<Base, Derived> : true_type
{
};

template<class Base, class Derived>
constexpr bool is_base_of_v = IsBaseOf<Base, Derived>::value;

}  // namespace based
