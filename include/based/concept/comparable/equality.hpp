#pragma once

#include "based/concept/comparable/equal.hpp"
#include "based/concept/comparable/not_equal.hpp"

namespace based::trait
{

// clang-format off
template<class T>
concept IsEqualityComparable = requires {
    requires(IsEqualComparable<T>);
    requires(IsNotEqualComparable<T>);
};
// clang-format on

}  // namespace based::trait
