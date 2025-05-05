#pragma once

#include <cassert>

#include "based/algorithms/sort/increasing_range.hpp"
#include "based/algorithms/sort/partition_point.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

namespace detail
{

template<typename T, Relation<T> Rel>
auto lower_bound_predicate(const T& goal, Rel rel)
{
  return [=](const T& val)
  {
    return !rel(val, goal);
  };
}

}  // namespace detail

template<ReadableForwardIterator I, IterRelation<I> Rel>
I lower_bound_n(
    I first, iter_dist_t<I> size, const iter_value_t<I>& val, Rel rel
)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range_n(first, size, rel));

  return partition_point_n(
      first, size, detail::lower_bound_predicate(val, rel)
  );
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I lower_bound(I first, I last, const iter_value_t<I>& val, Rel rel)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range(first, last, rel));

  return based::lower_bound_n(first, last - first, val, rel);
}

}  // namespace based
