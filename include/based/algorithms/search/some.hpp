#pragma once

#include "based/algorithms/search/find_if.hpp"
#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"

namespace based
{

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool some(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return find_if(first, last, pred) != last;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool some_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return find_if_n(first, size, pred).second != 0;
}

}  // namespace based
