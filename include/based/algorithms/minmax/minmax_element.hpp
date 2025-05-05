#pragma once

#include <functional>
#include <iterator>

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

// return first min and last max element
template<Iterator I, IterRelation<I> Rel>
std::pair<I, I> minmax_element(I first, I last, Rel rel)
{
  if (first == last) {
    return {last, last};
  }

  I mini = first++;
  if (first == last) {
    return {mini, mini};
  }

  I maxi = first++;
  if (rel(*maxi, *mini)) {
    std::swap(mini, maxi);
  }

  I next = std::next(first);
  while (first != last && next != last) {
    I pmini = first;
    I pmaxi = next;

    if (rel(*pmaxi, *pmini)) {
      std::swap(pmini, pmaxi);
    }

    if (rel(*pmini, *mini)) {
      mini = pmini;
    }

    if (!rel(*pmaxi, *maxi)) {
      maxi = pmaxi;
    }

    next++;
    first = next;
    next++;
  }

  if (first != last) {
    if (rel(*first, *mini)) {
      mini = first;
    } else if (!rel(*first, *maxi)) {
      maxi = first;
    }
  }

  return {mini, maxi};
}

template<Iterator I>
std::pair<I, I> minmax_element(I first, I last)
{
  return based::minmax_element(first, last, std::less<iter_value_t<I>>());
}

}  // namespace based
