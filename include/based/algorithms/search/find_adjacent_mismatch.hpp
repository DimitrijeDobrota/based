#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I, IterRelation<I> Rel>
I find_adjacent_mismatch(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (first == last) {
    return last;
  }

  auto crnt = *first;
  first++;
  while (first != last && rel(crnt, *first)) {
    crnt = *first;
    first++;
  }

  return first;
}

template<ReadableIterator I, IterRelation<I> Rel>
auto find_adjacent_mismatch_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (size == 0) {
    return std::make_pair(first, size);
  }

  auto crnt = *first;
  first++;
  size--;
  while (size != 0 && rel(crnt, *first)) {
    crnt = *first;
    size--;
    first++;
  }

  return std::make_pair(first, size);
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I find_adjacent_mismatch_forward(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (first == last) {
    return last;
  }

  I tmp;
  do {
    tmp = first;
    first++;
  } while (first != last && rel(*tmp, *first));

  return first;
}

}  // namespace based
