#include "based/integer.hpp"
#include "based/type_traits.hpp"

namespace based
{

template<Iterator I>
I successor(I itr)
{
  return ++itr;
}

template<Iterator I>
void increment(I& itr)
{
  // Precondition: next(itr) is defined
  itr = next(itr);
}

template<Iterator I>
I operator+(I first, iter_dist_t<I> size)
{
  // Precondition: size >= 0 & weak_range(first, size)
  while (!zero(size)) {
    size = predecessor(size);
    first = successor(first);
  }
  return first;
}

template<Iterator I>
iter_dist_t<I> operator-(I last, I first)
{
  // Precondition: bounded_range(first, last)
  iter_dist_t<I> cnt {0};
  while (first != last) {
    cnt = successor(cnt);
    first = successor(first);
  }
  return cnt;
}

}  // namespace based
