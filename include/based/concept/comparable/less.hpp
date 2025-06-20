#pragma once

#include "based/concept/is/same.hpp"
#include "based/trait/remove_reference.hpp"

namespace based
{

// clang-format off

template<typename T>
concept LessComparable = requires
(const trait::RemoveReference<T>& lhs, const trait::RemoveReference<T>& rhs)
{
	{lhs < rhs} -> SameAs<bool>;
	{rhs < lhs} -> SameAs<bool>;
};

// clang-format on

}  // namespace based
