#pragma once

#include "based/concept/procedure/predicate.hpp"

namespace based
{

template<typename T, Relation<T> Rel>
auto complement_of_converse(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return !rel(rhs, lhs);
  };
}

}  // namespace based
