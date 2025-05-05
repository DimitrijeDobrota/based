#pragma once

#include "based/concepts/is/same.hpp"
#include "based/type_traits/remove/reference.hpp"

namespace based
{

// clang-format off

template<typename T>
concept GreaterEqualComparable = requires
(const remove_reference_t<T>& lhs, const remove_reference_t<T>& rhs)
{
	{lhs >= rhs} -> SameAs<bool>;
	{rhs >= lhs} -> SameAs<bool>;
};

// clang-format on

}  // namespace based
