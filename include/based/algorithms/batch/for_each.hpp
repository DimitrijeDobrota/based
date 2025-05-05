#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/procedure_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

template<ReadableIterator I, IterUnaryProcedure<void, I> Proc>
Proc for_each(I first, I last, Proc proc)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    proc(*first);
    first++;
  }
  return proc;
}

template<ReadableIterator I, IterUnaryProcedure<void, I> Proc>
auto for_each_n(I first, iter_dist_t<I> size, Proc proc)
{
  // Precondition: readable_weak_range(first, size);
  while (size != 0) {
    size--;
    proc(*first);
    first++;
  }
  return std::make_pair(proc, first);
}

}  // namespace based
