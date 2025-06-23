#pragma once

#include "based/concept/is_constructible.hpp"
#include "based/trait/add_lvalue_reference.hpp"

namespace based::trait
{

template<class T>
concept IsCopyConstructible = IsConstructible<T, AddLValueReference<const T>>;

template<class T>
concept IsTriviallyCopyConstructible =
    IsTriviallyConstructible<T, AddLValueReference<const T>>;

template<class T>
concept IsNothrowCopyConstructible =
    IsNothrowConstructible<T, AddLValueReference<const T>>;

}  // namespace based::trait
