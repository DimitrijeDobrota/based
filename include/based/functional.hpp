#pragma once

#include <cassert>

#include "based/type_traits.hpp"

namespace based
{

template<typename T, Relation<T> R>
auto complement(R r)
{
  return [=](const T& a, const T& b)
  {
    return !r(a, b);
  };
}

template<typename T, Relation<T> R>
auto converse(R r)
{
  return [=](const T& a, const T& b)
  {
    return r(b, a);
  };
}

template<typename T, Relation<T> R>
auto complement_of_converse(R r)
{
  return [=](const T& a, const T& b)
  {
    return !r(b, a);
  };
}

template<typename T, Relation<T> R>
auto lower_bound_predicate(const T& a, R r)
{
  return [=](const T& x)
  {
    return !r(x, a);
  };
}

template<typename T, Relation<T> R>
auto upper_bound_predicate(const T& a, R r)
{
  return [=](const T& x)
  {
    return r(a, x);
  };
}

}  // namespace based
