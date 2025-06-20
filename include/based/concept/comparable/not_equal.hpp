#pragma once

#include "based/concept/is/same.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

// clang-format off

template<typename T>
concept NotEqualComparable = requires
(const RemoveReferenceT<T>& lhs, const RemoveReferenceT<T>& rhs)
{
	{lhs != rhs} -> SameAs<bool>;
	{rhs != lhs} -> SameAs<bool>;
};

// clang-format on

}  // namespace based
