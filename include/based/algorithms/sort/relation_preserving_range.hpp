#pragma once

#include "based/algorithms/search/find_adjacent_mismatch.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

template<ReadableIterator I, IterRelation<I> Rel>
bool relation_preserving_range(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return find_adjacent_mismatch(first, last, rel) == last;
}

template<ReadableIterator I, IterRelation<I> Rel>
bool relation_preserving_range_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return find_adjacent_mismatch_n(first, size, rel).second == 0;
}

}  // namespace based
