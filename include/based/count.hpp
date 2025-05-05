#pragma once

#include "based/concepts/iterator.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I, Iterator J>
J count(I first, I last, const iter_value_t<I>& val, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (*first == val) {
      cnt++;
    }
    first++;
  }
  return cnt;
}

template<ReadableIterator I>
iter_dist_t<I> count(I first, I last, const iter_value_t<I>& val)
{
  // Precondition: readable_bounded_range(first, last);
  return count(first, last, val, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
auto count_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val, J cnt)
{
  // Precondition: readable_weak_range(first, size);
  while (size != 0) {
    if (*first == val) {
      cnt++;
    }
    size--;
    first++;
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I>
auto count_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  return count_n(first, size, val, iter_dist_t<I> {0});
}

}  // namespace based
