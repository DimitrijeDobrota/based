#pragma once

#include "based/concept/comparable/equality.hpp"
#include "based/concept/comparable/greater.hpp"
#include "based/concept/comparable/greater_equal.hpp"
#include "based/concept/comparable/less.hpp"
#include "based/concept/comparable/less_equal.hpp"

namespace based
{

// clang-format off

template<typename T>
concept totally_ordered = requires {
	requires(EqualityComparable<T>);
	requires(LessComparable<T>);
	requires(GreaterComparable<T>);
	requires(LessEqualComparable<T>);
	requires(GreaterEqualComparable<T>);
};

// clang-format on

}  // namespace based
