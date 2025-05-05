#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
J count_if_not(I first, I last, Pred pred, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (!pred(*first)) {
      cnt++;
    }
    first++;
  }
  return cnt;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
iter_dist_t<I> count_if_not(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return count_if_not(first, last, pred, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
auto count_if_not_n(I first, iter_dist_t<I> size, Pred pred, J cnt)
{
  // Precondition: readable_weak_range(first, size);
  while (size != 0) {
    if (!pred(*first)) {
      cnt++;
    }
    size--;
    first++;
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto count_if_not_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return count_if_not_n(first, size, pred, iter_dist_t<I> {0});
}

}  // namespace based
