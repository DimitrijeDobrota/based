#pragma once

#include <cassert>

#include "based/type_traits.hpp"

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

template<typename T, Relation<T> Rel>
auto lower_bound_predicate(const T& goal, Rel rel)
{
  return [=](const T& val)
  {
    return !rel(val, goal);
  };
}

template<typename T, Relation<T> Rel>
auto upper_bound_predicate(const T& goal, Rel rel)
{
  return [=](const T& val)
  {
    return rel(goal, val);
  };
}

}  // namespace based
