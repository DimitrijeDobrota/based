#pragma once

#include "based/concept/is_constructible.hpp"
#include "based/trait/add_rvalue_reference.hpp"

namespace based::trait
{

template<class T>
concept IsMoveConstructible = IsConstructible<T, AddRValueReference<T>>;

template<class T>
concept IsTriviallyMoveConstructible =
    IsTriviallyConstructible<T, AddRValueReference<T>>;

template<class T>
concept IsNothrowMoveConstructible =
    IsNothrowConstructible<T, AddRValueReference<T>>;

}  // namespace based::trait
