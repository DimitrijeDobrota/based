#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if_not(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last && pred(*first)) {
    first++;
  }
  return first;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto find_if_not_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  while (size != 0 && pred(*first)) {
    size--;
    first++;
  }
  return std::make_pair(first, size);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if_not_unguarded(I first, Pred pred)
{
  // Precondition: readable_bounded_range(first, last) && not_all(f, d, p);
  while (pred(*first)) {
    first++;
  }
  return first;
}

}  // namespace based
