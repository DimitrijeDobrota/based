#pragma once

#include "based/concepts/procedure/predicate.hpp"

namespace based
{

template<typename T, Relation<T> Rel>
auto complement(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return !rel(lhs, rhs);
  };
}

}  // namespace based
