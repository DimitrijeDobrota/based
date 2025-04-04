#include "based/integer.hpp"
#include "based/type_traits.hpp"

namespace based
{

template<Iterator I>
I next(I i)
{
  return ++i;
}

template<Iterator I>
void increment(I& x)
{
  // Precondition: next(x) is defined
  x = next(x);
}

template<Iterator I>
I operator+(I f, distance_t<I> n)
{
  // Precondition: n >= 0 & weak_range(f, n)
  while (!zero(n)) {
    n = predecessor(n);
    f = based::next(f);
  }
  return f;
}

template<Iterator I>
distance_t<I> operator-(I d, I f)
{
  // Precondition: bounded_range(f, d)
  distance_t<I> n {0};
  while (f != d) {
    n = successor(n);
    f = next(f);
  }
  return n;
}

}  // namespace based
