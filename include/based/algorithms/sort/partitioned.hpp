#pragma once

#include "based/algorithms/search/find_if.hpp"
#include "based/algorithms/search/find_if_not.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
bool partitioned_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_bounded_range(first, size)
  std::tie(first, size) = find_if_n(first, size, pred);
  return find_if_not_n(first, size, pred).second == 0;
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
bool partitioned(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last)
  return find_if_not(find_if(first, last, pred), last, pred) == last;
}

}  // namespace based
