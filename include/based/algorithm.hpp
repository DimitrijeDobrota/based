#pragma once

#include <functional>
#include <utility>

#include "based/iterator.hpp"
#include "based/type_traits.hpp"

namespace based
{

namespace detail
{

/* ----- Min and Max ----- */

template<typename P, typename Arg>
concept NoninputRelation = requires {
  requires(RegularProcedure<P, Arg, Arg>);
  requires(std::same_as<bool, codomain_t<P, Arg, Arg>>);
  requires(arity_v<P, Arg, Arg> == 2);
};

}  // namespace detail

// returns min element, first if equal
template<BareRegular T, BareRegular U, detail::NoninputRelation<T> R>
  requires BareSameAs<T, U>
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

// returns max element, second if equal
template<BareRegular T, BareRegular U, detail::NoninputRelation<T> R>
  requires BareSameAs<T, U>
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

/* ----- Bounded Range Algorithms ----- */

// return first min element
template<Iterator I, IterRelation<I> R>
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

// return last max element
template<Iterator I, IterRelation<I> R>
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
template<Iterator I, IterRelation<I> R>
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

  I next = successor(first);
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

template<ReadableIterator I, IterUnaryProcedure<I> Proc>
Proc for_each(I f, I d, Proc proc)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    proc(*f);
    f = successor(f);
  }
  return proc;
}

template<ReadableIterator I>
I find(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && *f != x) {
    f = successor(f);
  }
  return f;
}

template<ReadableIterator I>
I find_not(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && *f == x) {
    f = successor(f);
  }
  return f;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
I find_if(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && !p(*f)) {
    f = successor(f);
  }
  return f;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
I find_if_not(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d && p(*f)) {
    f = successor(f);
  }
  return f;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool all(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if_not(f, d, p) == d;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool none(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if(f, d, p) == d;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool not_all(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return f == d || find_if_not(f, d, p) != d;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool some(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return find_if(f, d, p) != d;
}

template<ReadableIterator I, Iterator J>
J count(I f, I d, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (*f == x) {
      j++;
    }
    f = successor(f);
  }
  return j;
}

template<ReadableIterator I>
iter_dist_t<I> count(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  return count(f, d, x, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
J count_not(I f, I d, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (*f != x) {
      j++;
    }
    f = successor(f);
  }
  return j;
}

template<ReadableIterator I>
iter_dist_t<I> count_not(I f, I d, const iter_value_t<I>& x)
{
  // Precondition: readable_bounded_range(f, d);
  return count_not(f, d, x, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> P, Iterator J>
J count_if(I f, I d, P p, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (p(*f)) {
      j++;
    }
    f = successor(f);
  }
  return j;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
iter_dist_t<I> count_if(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return count_if(f, d, p, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> P, Iterator J>
J count_if_not(I f, I d, P p, J j)
{
  // Precondition: readable_bounded_range(f, d);
  while (f != d) {
    if (!p(*f)) {
      j++;
    }
    f = successor(f);
  }
  return j;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
iter_dist_t<I> count_if_not(I f, I d, P p)
{
  // Precondition: readable_bounded_range(f, d);
  return count_if_not(f, d, p, iter_dist_t<I> {0});
}

template<Iterator I, UnaryFunction<I> F, BinaryOperation<codomain_t<F, I>> Op>
auto reduce_nonempty(I f, I d, Op op, F fun)
{
  assert(f != d);
  // Precondition: bounded_range(f,d)
  // Precondition: partially_associative(op)

  auto r = fun(f);
  f = successor(f);
  while (f != d) {
    r = op(r, fun(f));
    f = successor(f);
  }
  return r;
}

template<Iterator I, UnaryFunction<I> F, BinaryOperation<codomain_t<F, I>> Op>
auto reduce(
    I f, I d, Op op, F fun, const decltype(reduce_nonempty(f, d, op, fun))& z)
{
  // Precondition: bounded_range(f,d)
  // Precondition: partially_associative(op)
  if (f == d) {
    return z;
  }
  return reduce_nonempty(f, d, op, fun);
}

template<Iterator I, UnaryFunction<I> F, BinaryOperation<codomain_t<F, I>> Op>
auto reduce_nonzero(
    I f, I d, Op op, F fun, const decltype(reduce_nonempty(f, d, op, fun))& z)
{
  // Precondition: bounded_range(f,d)
  // Precondition: partially_associative(op)
  codomain_t<F, I> x;
  do {
    if (f == d) {
      return z;
    }
    x = fun(f);
    f = successor(f);
  } while (x == z);

  while (f != d) {
    auto y = fun(f);
    if (y != z) {
      x = op(x, y);
    }
    f = successor(f);
  }
  return x;
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> R>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch(I0 f0, I0 d0, I1 f1, I1 d1, R r)
{
  // Precondition: readable_bounded_range(f0,d0)
  // Precondition: readable_bounded_range(f1,d1)
  while (f0 != d0 && f1 != d1 && r(*f0, *f1)) {
    f0 = successor(f0);
    f1 = successor(f1);
  }
  return std::make_pair(f0, f1);
}

template<ReadableIterator I, IterRelation<I> R>
I find_adjacent_mismatch(I f, I d, R r)
{
  // Precondition: readable_bounded_range(f,d)

  if (f == d) {
    return d;
  }

  auto x = *f;
  f = successor(f);
  while (f != d && r(x, *f)) {
    x = *f;
    f = successor(f);
  }

  return f;
}

/* ----- Counted Range Algorithms ----- */

template<ReadableIterator I, IterUnaryProcedure<I> Proc>
auto for_each_n(I f, iter_dist_t<I> n, Proc proc)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n)) {
    n = predecessor(n);
    proc(*f);
    f = successor(f);
  }
  return std::make_pair(proc, f);
}

template<ReadableIterator I>
auto find_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n) && *f != x) {
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, n);
}

template<ReadableIterator I>
auto find_not_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n) && *f == x) {
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, n);
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
auto find_if_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n) && !p(*f)) {
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, n);
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
auto find_if_not_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n) && p(*f)) {
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, n);
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool all_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, d);
  return find_if_not_n(f, n, p).second == 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool none_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  return find_if_n(f, n, p).second == 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool not_all_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  return n == 0 || find_if_not_n(f, n, p).second != 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
bool some_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  return find_if_n(f, n, p).second != 0;
}

template<ReadableIterator I, Iterator J>
auto count_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n)) {
    if (*f == x) {
      j++;
    }
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, j);
}

template<ReadableIterator I>
auto count_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x)
{
  // Precondition: readable_weak_range(f, n);
  return count_n(f, n, x, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
auto count_not_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x, J j)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n)) {
    if (*f != x) {
      j++;
    }
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, j);
}

template<ReadableIterator I>
auto count_not_n(I f, iter_dist_t<I> n, const iter_value_t<I>& x)
{
  // Precondition: readable_weak_range(f, n);
  return count_not_n(f, n, x, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> P, Iterator J>
auto count_if_n(I f, iter_dist_t<I> n, P p, J j)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n)) {
    if (p(*f)) {
      j++;
    }
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, j);
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
auto count_if_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  return count_if_n(f, n, p, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> P, Iterator J>
auto count_if_not_n(I f, iter_dist_t<I> n, P p, J j)
{
  // Precondition: readable_weak_range(f, n);
  while (!zero(n)) {
    if (!p(*f)) {
      j++;
    }
    n = predecessor(n);
    f = successor(f);
  }
  return std::make_pair(f, j);
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
auto count_if_not_n(I f, iter_dist_t<I> n, P p)
{
  // Precondition: readable_weak_range(f, n);
  return count_if_not_n(f, n, p, iter_dist_t<I> {0});
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> R>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_n(I0 f0, iter_dist_t<I0> n0, I1 f1, I1 d1, R r)
{
  // Precondition: readable_weak_range(f0,n0)
  // Precondition: readable_bounded_range(f1,d1)
  while (!zero(n0) && f1 != d1 && r(*f0, *f1)) {
    n0 = predecessor(n0);
    f0 = successor(f0);
    f1 = successor(f1);
  }
  return std::make_tuple(f0, n0, f1);
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> R>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_m(I0 f0, I0 d0, I1 f1, iter_dist_t<I1> n1, R r)
{
  // Precondition: readable_bounded_range(f0,d0)
  // Precondition: readable_weak_range(f1,n1)
  while (f0 != d0 && !zero(n1) && r(*f0, *f1)) {
    n1 = predecessor(n1);
    f0 = successor(f0);
    f1 = successor(f1);
  }
  return std::make_tuple(f0, f1, n1);
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> R>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_n_m(
    I0 f0, iter_dist_t<I0> n0, I1 f1, iter_dist_t<I1> n1, R r)
{
  // Precondition: readable_weak_range(f0,n0)
  // Precondition: readable_weak_range(f1,n1)
  while (!zero(n0) && !zero(n1) && r(*f0, *f1)) {
    n0 = predecessor(n0);
    n1 = predecessor(n1);
    f0 = successor(f0);
    f1 = successor(f1);
  }
  return std::make_tuple(f0, n0, f1, n1);
}

/* ----- Sentinel Ranges ----- */

template<ReadableIterator I, IterUnaryPredicate<I> P>
I find_if_unguarded(I f, P p)
{
  // Precondition: readable_bounded_range(f, d) && some(f, d, p);
  while (!p(*f)) {
    f = successor(f);
  }
  return f;
}

template<ReadableIterator I, IterUnaryPredicate<I> P>
I find_if_not_unguarded(I f, P p)
{
  // Precondition: readable_bounded_range(f, d) && not_all(f, d, p);
  while (p(*f)) {
    f = successor(f);
  }
  return f;
}

}  // namespace based
