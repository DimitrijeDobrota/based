#pragma once

#include "based/concept/comparable/equal.hpp"
#include "based/concept/comparable/not_equal.hpp"

namespace based
{

// clang-format off

template<typename T>
concept EqualityComparable = requires {
	requires(EqualComparable<T>);
    requires(NotEqualComparable<T>);
};

// clang-format on

}  // namespace based
