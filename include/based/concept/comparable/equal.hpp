#pragma once

#include "based/concept/is_same.hpp"
#include "based/trait/remove_reference.hpp"

namespace based::trait
{

// clang-format off
template<class T>
concept EqualComparable = requires
(const RemoveReference<T>& lhs, const RemoveReference<T>& rhs)
{
  { lhs == rhs } -> IsSame<bool>;
  { rhs == lhs } -> IsSame<bool>;
};
// clang-format on

}  // namespace based::trait
