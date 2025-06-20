#pragma once

#include "based/concept/is_arithmetic.hpp"
#include "based/concept/is_enum.hpp"
#include "based/concept/is_member_pointer.hpp"
#include "based/concept/is_null_pointer.hpp"
#include "based/concept/is_pointer.hpp"

namespace based::trait
{

template<class T>
concept IsScalar = IsArithmetic<T> || IsEnum<T> || IsPointer<T>
    || IsMemberPointer<T> || IsNullPointer<T>;

}  // namespace based::trait
