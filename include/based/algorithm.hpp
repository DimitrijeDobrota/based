#pragma once

#include <functional>
#include <utility>

#include "based/iterator.hpp"
#include "based/type_traits.hpp"

namespace based
{

// returns min element, first if equal
template<Relation R, BareRegular T, BareRegular U>
  requires BareSameAs<T, U> && BareSameAs<T, domain_t<R>>
decltype(auto) min(T&& lhs, U&& rhs, R r)
{
  return r(rhs, lhs) ? std::forward<U>(rhs) : std::forward<T>(lhs);
}

// returns min element, first if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
      std::forward<T>(lhs), std::forward<U>(rhs), std::less<bare_t<T>>());
}

// return first min element
template<Iterator I, Relation R>
  requires SameAs<iter_value_t<I>, domain_t<R>>
I min_element(I first, I last, R r)
{
  if (first == last) {
    return last;
  }

  I mini = first++;
  while (first != last) {
    if (r(*first, *mini)) {
      mini = first;
    }
    first++;
  }
  return mini;
}

template<Iterator I>
I min_element(I first, I last)
{
  return based::min_element(first, last, std::less<iter_value_t<I>>());
}

// returns max element, second if equal
template<Relation R, BareRegular T, BareRegular U>
  requires BareSameAs<T, U> && BareSameAs<T, domain_t<R>>
decltype(auto) max(T&& lhs, U&& rhs, R r)
{
  return r(rhs, lhs) ? std::forward<T>(lhs) : std::forward<U>(rhs);
}

// returns max element, second if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) max(T&& lhs, U&& rhs)
{
  return based::max(
      std::forward<T>(lhs), std::forward<U>(rhs), std::less<bare_t<T>>());
}

// return last max element
template<Iterator I, Relation R>
  requires std::same_as<iter_value_t<I>, domain_t<R>>
I max_element(I first, I last, R r)
{
  if (first == last) {
    return last;
  }

  I maxi = first++;
  while (first != last) {
    if (!r(*first, *maxi)) {
      maxi = first;
    }
    first++;
  }
  return maxi;
}

template<Iterator I>
I max_element(I first, I last)
{
  return based::max_element(first, last, std::less<iter_value_t<I>>());
}

// return first min and last max element
template<Iterator I, Relation R>
  requires std::same_as<iter_value_t<I>, domain_t<R>>
std::pair<I, I> minmax_element(I first, I last, R r)
{
  if (first == last) {
    return {last, last};
  }

  I mini = first++;
  if (first == last) {
    return {mini, mini};
  }

  I maxi = first++;
  if (r(*maxi, *mini)) {
    std::swap(mini, maxi);
  }

  I next = based::next(first);
  while (first != last && next != last) {
    I pmini = first;
    I pmaxi = next;

    if (r(*pmaxi, *pmini)) {
      std::swap(pmini, pmaxi);
    }

    if (r(*pmini, *mini)) {
      mini = pmini;
    }

    if (!r(*pmaxi, *maxi)) {
      maxi = pmaxi;
    }

    next++;
    first = next;
    next++;
  }

  if (first != last) {
    if (r(*first, *mini)) {
      mini = first;
    } else if (!r(*first, *maxi)) {
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

template<ReadableIterator I, UnaryProcedure Proc>
  requires SameAs<iter_value_t<I>, domain_t<Proc>>
Proc for_each(I f, I d, Proc proc)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    proc(*f);
    f = next(f);
  }
  return proc;
}

template<ReadableIterator I>
I find(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && *f != x) {
    f == next(f);
  }
  return f;
}

template<ReadableIterator I>
I find_not(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && *f == x) {
    f == next(f);
  }
  return f;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
I find_if(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && !p(*f)) {
    f == next(f);
  }
  return f;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
I find_if_not(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && p(*f)) {
    f == next(f);
  }
  return f;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
bool all(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if_not(f, d, p) == d;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
bool none(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if(f, d, p) == d;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
bool not_all(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if_not(f, d, p) != d;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
bool some(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if(f, d, p) != d;
}

template<ReadableIterator I, UnaryPredicate P, Iterator J>
  requires SameAs<iter_value_t<I>, domain_t<P>>
J count_if(I f, I d, P p, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (p(*f)) {
      j = next(j);
    }
    f = next(f);
  }
  return j;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
iter_dist_t<I> count_if(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return count_if(f, d, p, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
J count(I f, I d, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (*f == x) {
      j = next(j);
    }
    f = next(f);
  }
  return j;
}

template<ReadableIterator I>
iter_dist_t<I> count(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  return count(f, d, x, iter_dist_t<I> {0});
}

template<ReadableIterator I, UnaryPredicate P, Iterator J>
  requires SameAs<iter_value_t<I>, domain_t<P>>
J count_if_not(I f, I d, P p, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (!p(*f)) {
      j = next(j);
    }
    f = next(f);
  }
  return j;
}

template<ReadableIterator I, UnaryPredicate P>
  requires SameAs<iter_value_t<I>, domain_t<P>>
iter_dist_t<I> count_if_not(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return count_if_not(f, d, p, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
J count_not(I f, I d, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (*f != x) {
      j = next(j);
    }
    f = next(f);
  }
  return j;
}

template<ReadableIterator I>
iter_dist_t<I> count_not(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  return count_not(f, d, x, iter_dist_t<I> {0});
}

}  // namespace based
