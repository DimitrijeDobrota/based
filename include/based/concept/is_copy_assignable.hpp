#pragma once

#include "based/concept/is_assignable.hpp"
#include "based/trait/add_lvalue_reference.hpp"

namespace based::trait
{

template<class T>
concept IsCopyAssignable =
    IsAssignable<AddLValueReference<T>, AddLValueReference<const T>>;

template<class T>
concept IsTriviallyCopyAssignable =
    IsTriviallyAssignable<AddLValueReference<T>, AddLValueReference<const T>>;

template<class T>
concept IsNothrowCopyAssignable =
    IsNothrowAssignable<AddLValueReference<T>, AddLValueReference<const T>>;

}  // namespace based::trait
