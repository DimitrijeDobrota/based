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

template<typename T, Relation<T> Rel>
auto converse(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return rel(rhs, lhs);
  };
}

template<typename T, Relation<T> Rel>
auto complement_of_converse(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return !rel(rhs, lhs);
  };
}

}  // namespace based
