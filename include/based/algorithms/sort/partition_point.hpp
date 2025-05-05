#pragma once

#include <cassert>

#include "based/algorithms/sort/partitioned.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
I partition_point_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_bounded_range(first, size)
  assert(partitioned_n(first, size, pred));

  while (size != 0) {
    const auto hlf = size / 2;
    I mid = first + hlf;
    if (pred(*mid)) {
      size = hlf;
    } else {
      size -= hlf + 1;
      first = mid + 1;
    }
  }
  return first;
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
I partition_point(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last)
  assert(partitioned(first, last, pred));

  return partition_point_n(first, last - first, pred);
}

}  // namespace based
