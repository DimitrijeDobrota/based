#pragma once

#include <functional>

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate_iter.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

// return first min element
template<Iterator I, IterRelation<I> Rel>
I min_element(I first, I last, Rel rel)
{
  if (first == last) {
    return last;
  }

  I mini = first;
  first++;
  while (first != last) {
    if (rel(*first, *mini)) {
      mini = first;
    }
    first++;
  }
  return mini;
}

// return first min element
template<Iterator I>
I min_element(I first, I last)
{
  return based::min_element(first, last, std::less<iter_value_t<I>>());
}

}  // namespace based
