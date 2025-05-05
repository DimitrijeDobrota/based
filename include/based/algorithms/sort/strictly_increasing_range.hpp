#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

template<ReadableIterator I, IterRelation<I> Rel>
bool strictly_increasing_range(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return relation_preserving_range(first, last, rel);
}

template<ReadableIterator I, IterRelation<I> Rel>
bool strictly_increasing_range_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return relation_preserving_range_n(first, size, rel);
}

}  // namespace based
