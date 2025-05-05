#pragma once

#include "based/concepts/iterator.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I>
I find_not(I first, I last, const iter_value_t<I>& val)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last && *first == val) {
    first++;
  }
  return first;
}

template<ReadableIterator I>
auto find_not_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  while (size != 0 && *first == val) {
    size--;
    first++;
  }
  return std::make_pair(first, size);
}

}  // namespace based
