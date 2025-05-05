#pragma once

#include "based/concepts/comparable/equality.hpp"
#include "based/concepts/comparable/greater.hpp"
#include "based/concepts/comparable/greater_equal.hpp"
#include "based/concepts/comparable/less.hpp"
#include "based/concepts/comparable/less_equal.hpp"

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
