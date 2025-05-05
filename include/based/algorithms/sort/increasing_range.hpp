#pragma once

#include "based/algorithms/sort/relation_preserving_range.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/functional/predicate.hpp"

namespace based
{

template<ReadableIterator I, IterRelation<I> Rel>
bool increasing_range(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return relation_preserving_range(
      first, last, complement_of_converse<iter_value_t<I>>(rel)
  );
}

template<ReadableIterator I, IterRelation<I> Rel>
bool increasing_range_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return relation_preserving_range_n(
      first, size, complement_of_converse<iter_value_t<I>>(rel)
  );
}

}  // namespace based
