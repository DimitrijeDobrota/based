#pragma once

#include "based/concept/is_same.hpp"
#include "based/trait/remove_reference.hpp"

namespace based
{

// clang-format off

template<typename T>
concept NotEqualComparable = requires
(const trait::RemoveReference<T>& lhs, const trait::RemoveReference<T>& rhs)
{
	{lhs != rhs} -> trait::IsSame<bool>;
	{rhs != lhs} -> trait::IsSame<bool>;
};

// clang-format on

}  // namespace based
