#pragma once

#include "based/concept/is/same.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

// clang-format off

template<typename T>
concept NotEqualComparable = requires
(const remove_reference_t<T>& lhs, const remove_reference_t<T>& rhs)
{
	{lhs != rhs} -> SameAs<bool>;
	{rhs != lhs} -> SameAs<bool>;
};

// clang-format on

}  // namespace based
