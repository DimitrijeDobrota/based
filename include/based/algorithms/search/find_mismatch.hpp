#pragma once

#include <tuple>
#include <utility>

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch(I0 first0, I0 last0, I1 first1, I1 last1, Rel rel)
{
  // Precondition: readable_bounded_range(first0, last0)
  // Precondition: readable_bounded_range(first1, last1)
  while (first0 != last0 && first1 != last1 && rel(*first0, *first1)) {
    first0++;
    first1++;
  }
  return std::make_pair(first0, first1);
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_n(
    I0 first0, iter_dist_t<I0> size0, I1 first1, I1 last1, Rel rel
)
{
  // Precondition: readable_weak_range(first0, size0)
  // Precondition: readable_bounded_range(first1,last1)
  while (size0 != 0 && first1 != last1 && rel(*first0, *first1)) {
    first0++;
    first1++;
    size0--;
  }
  return std::make_tuple(first0, size0, first1);
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_m(
    I0 first0, I0 last0, I1 first1, iter_dist_t<I1> size1, Rel rel
)
{
  // Precondition: readable_bounded_range(first0,last0)
  // Precondition: readable_weak_range(first1, size1)
  while (first0 != last0 && size1 != 0 && rel(*first0, *first1)) {
    first0++;
    first1++;
    size1--;
  }
  return std::make_tuple(first0, first1, size1);
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_n_m(
    I0 first0, iter_dist_t<I0> size0, I1 first1, iter_dist_t<I1> size1, Rel rel
)
{
  // Precondition: readable_weak_range(first0, size0)
  // Precondition: readable_weak_range(first1, size1)
  while (size0 != 0 && size1 != 0 && rel(*first0, *first1)) {
    first0++;
    first1++;
    size0--;
    size1--;
  }
  return std::make_tuple(first0, size0, first1, size1);
}

}  // namespace based
