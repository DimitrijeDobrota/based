#pragma once

#include <functional>

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

// return last max element
template<Iterator I, IterRelation<I> Rel>
I max_element(I first, I last, Rel rel)
{
  if (first == last) {
    return last;
  }

  I maxi = first;
  first++;
  while (first != last) {
    if (!rel(*first, *maxi)) {
      maxi = first;
    }
    first++;
  }
  return maxi;
}

// return last max element
template<Iterator I>
I max_element(I first, I last)
{
  return based::max_element(first, last, std::less<iter_value_t<I>>());
}

}  // namespace based
