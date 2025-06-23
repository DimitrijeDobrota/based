#pragma once

#include "based/concept/is_assignable.hpp"
#include "based/trait/add_lvalue_reference.hpp"
#include "based/trait/add_rvalue_reference.hpp"

namespace based::trait
{

template<class T>
concept IsMoveAssignable =
    IsAssignable<AddLValueReference<T>, AddRValueReference<T>>;

template<class T>
concept IsTriviallyMoveAssignable =
    IsTriviallyAssignable<AddLValueReference<T>, AddRValueReference<T>>;

template<class T>
concept IsNothrowMoveAssignable =
    IsNothrowAssignable<AddLValueReference<T>, AddRValueReference<T>>;

}  // namespace based::trait
