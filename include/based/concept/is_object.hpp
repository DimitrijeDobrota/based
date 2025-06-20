#pragma once

#include "based/concept/is_array.hpp"
#include "based/concept/is_class.hpp"
#include "based/concept/is_scalar.hpp"
#include "based/concept/is_union.hpp"

namespace based::trait
{

template<class T>
concept IsObject = IsScalar<T> || IsArray<T> || IsUnion<T> || IsClass<T>;

}  // namespace based::trait
