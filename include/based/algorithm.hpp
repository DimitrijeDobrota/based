#pragma once

#include <functional>
#include <utility>

#include "based/functional.hpp"
#include "based/iterator.hpp"
#include "based/type_traits.hpp"

namespace based
{

namespace detail
{

/* ----- Min and Max ----- */

template<typename P, typename Arg>
concept NoninputRelation = RegularProcedure<P, bool, Arg, Arg>;

}  // namespace detail

// returns min element, first if equal
template<BareRegular T, BareRegular U, detail::NoninputRelation<T> Rel>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? std::forward<U>(rhs) : std::forward<T>(lhs);
}

// returns min element, first if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
      std::forward<T>(lhs), std::forward<U>(rhs), std::less<bare_t<T>>()
  );
}

// returns max element, second if equal
template<BareRegular T, BareRegular U, detail::NoninputRelation<T> Rel>
  requires BareSameAs<T, U>
decltype(auto) max(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? std::forward<T>(lhs) : std::forward<U>(rhs);
}

// returns max element, second if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) max(T&& lhs, U&& rhs)
{
  return based::max(
      std::forward<T>(lhs), std::forward<U>(rhs), std::less<bare_t<T>>()
  );
}

/* ----- Bounded Range Algorithms ----- */

// return first min element
template<Iterator I, IterRelation<I> Rel>
I min_element(I first, I last, Rel rel)
{
  if (first == last) {
    return last;
  }

  I mini = first++;
  while (first != last) {
    if (rel(*first, *mini)) {
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
template<Iterator I, IterRelation<I> Rel>
I max_element(I first, I last, Rel rel)
{
  if (first == last) {
    return last;
  }

  I maxi = first++;
  while (first != last) {
    if (!rel(*first, *maxi)) {
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

  I next = successor(first);
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

template<ReadableIterator I, IterUnaryProcedure<void, I> Proc>
Proc for_each(I first, I last, Proc proc)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    proc(*first);
    first = successor(first);
  }
  return proc;
}

template<ReadableIterator I>
I find(I first, I lst, const iter_value_t<I>& val)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != lst && *first != val) {
    first = successor(first);
  }
  return first;
}

template<ReadableIterator I>
I find_not(I first, I last, const iter_value_t<I>& val)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last && *first == val) {
    first = successor(first);
  }
  return first;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last && !pred(*first)) {
    first = successor(first);
  }
  return first;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if_not(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last && pred(*first)) {
    first = successor(first);
  }
  return first;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool all(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return find_if_not(first, last, pred) == last;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool none(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return find_if(first, last, pred) == last;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool not_all(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return first == last || find_if_not(first, last, pred) != last;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool some(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return find_if(first, last, pred) != last;
}

template<ReadableIterator I, Iterator J>
J count(I first, I last, const iter_value_t<I>& val, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (*first == val) {
      cnt++;
    }
    first = successor(first);
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
J count_not(I first, I last, const iter_value_t<I>& val, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (*first != val) {
      cnt++;
    }
    first = successor(first);
  }
  return cnt;
}

template<ReadableIterator I>
iter_dist_t<I> count_not(I first, I last, const iter_value_t<I>& val)
{
  // Precondition: readable_bounded_range(first, last);
  return count_not(first, last, val, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
J count_if(I first, I last, Pred pred, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (pred(*first)) {
      cnt++;
    }
    first = successor(first);
  }
  return cnt;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
iter_dist_t<I> count_if(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return count_if(first, last, pred, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
J count_if_not(I first, I last, Pred pred, J cnt)
{
  // Precondition: readable_bounded_range(first, last);
  while (first != last) {
    if (!pred(*first)) {
      cnt++;
    }
    first = successor(first);
  }
  return cnt;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
iter_dist_t<I> count_if_not(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last);
  return count_if_not(first, last, pred, iter_dist_t<I> {0});
}

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto reduce_nonempty(I first, I last, Op opr, F fun)
{
  assert(first != last);
  // Precondition: bounded_range(first, last)
  // Precondition: partially_associative(opr)

  auto res = fun(first);
  first = successor(first);
  while (first != last) {
    res = opr(res, fun(first));
    first = successor(first);
  }
  return res;
}

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto reduce(
    I first,
    I last,
    Op opr,
    F fun,
    const decltype(reduce_nonempty(first, last, opr, fun))& zero
)
{
  // Precondition: bounded_range(first, last)
  // Precondition: partially_associative(opr)
  if (first == last) {
    return zero;
  }
  return reduce_nonempty(first, last, opr, fun);
}

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto reduce_nonzero(
    I first,
    I last,
    Op opr,
    F fun,
    const decltype(reduce_nonempty(first, last, opr, fun))& zero
)
{
  // Precondition: bounded_range(first, last)
  // Precondition: partially_associative(opr)
  ret_t<F, I> res;
  do {
    if (first == last) {
      return zero;
    }
    res = fun(first);
    first = successor(first);
  } while (res == zero);

  while (first != last) {
    auto crnt = fun(first);
    if (crnt != zero) {
      res = opr(res, crnt);
    }
    first = successor(first);
  }
  return res;
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch(I0 first0, I0 last0, I1 first1, I1 last1, Rel rel)
{
  // Precondition: readable_bounded_range(first0, last0)
  // Precondition: readable_bounded_range(first1, last1)
  while (first0 != last0 && first1 != last1 && rel(*first0, *first1)) {
    first0 = successor(first0);
    first1 = successor(first1);
  }
  return std::make_pair(first0, first1);
}

template<ReadableIterator I, IterRelation<I> Rel>
I find_adjacent_mismatch(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (first == last) {
    return last;
  }

  auto crnt = *first;
  first = successor(first);
  while (first != last && rel(crnt, *first)) {
    crnt = *first;
    first = successor(first);
  }

  return first;
}

template<ReadableIterator I, IterRelation<I> Rel>
bool relation_preserving(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return find_adjacent_mismatch(first, last, rel) == last;
}

template<ReadableIterator I, IterRelation<I> Rel>
bool strictly_increasing_range(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return relation_preserving(first, last, rel);
}

template<ReadableIterator I, IterRelation<I> Rel>
bool increasing_range(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)
  // Precondition: weak_ordering(rel);
  return relation_preserving(
      first, last, complement_of_converse<iter_value_t<I>>(rel)
  );
}

/* ----- Counted Range Algorithms ----- */

template<ReadableIterator I, IterUnaryProcedure<void, I> Proc>
auto for_each_n(I first, iter_dist_t<I> size, Proc proc)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size)) {
    size = predecessor(size);
    proc(*first);
    first = successor(first);
  }
  return std::make_pair(proc, first);
}

template<ReadableIterator I>
auto find_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size) && *first != val) {
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, size);
}

template<ReadableIterator I>
auto find_not_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size) && *first == val) {
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, size);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto find_if_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size) && !pred(*first)) {
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, size);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto find_if_not_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size) && pred(*first)) {
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, size);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool all_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, last);
  return find_if_not_n(first, size, pred).second == 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool none_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return find_if_n(first, size, pred).second == 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool not_all_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return size == 0 || find_if_not_n(first, size, pred).second != 0;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
bool some_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return find_if_n(first, size, pred).second != 0;
}

template<ReadableIterator I, Iterator J>
auto count_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val, J cnt)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size)) {
    if (*first == val) {
      cnt++;
    }
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I>
auto count_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  return count_n(first, size, val, iter_dist_t<I> {0});
}

template<ReadableIterator I, Iterator J>
auto count_not_n(
    I first, iter_dist_t<I> size, const iter_value_t<I>& val, J cnt
)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size)) {
    if (*first != val) {
      cnt++;
    }
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I>
auto count_not_n(I first, iter_dist_t<I> size, const iter_value_t<I>& val)
{
  // Precondition: readable_weak_range(first, size);
  return count_not_n(first, size, val, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
auto count_if_n(I first, iter_dist_t<I> size, Pred pred, J cnt)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size)) {
    if (pred(*first)) {
      cnt++;
    }
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto count_if_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return count_if_n(first, size, pred, iter_dist_t<I> {0});
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred, Iterator J>
auto count_if_not_n(I first, iter_dist_t<I> size, Pred pred, J cnt)
{
  // Precondition: readable_weak_range(first, size);
  while (!zero(size)) {
    if (!pred(*first)) {
      cnt++;
    }
    size = predecessor(size);
    first = successor(first);
  }
  return std::make_pair(first, cnt);
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
auto count_if_not_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_weak_range(first, size);
  return count_if_not_n(first, size, pred, iter_dist_t<I> {0});
}

template<ReadableIterator I0, ReadableIterator I1, IterRelation<I0> Rel>
  requires BareSameAs<iter_value_t<I0>, iter_value_t<I1>>
auto find_mismatch_n(
    I0 first0, iter_dist_t<I0> size0, I1 first1, I1 last1, Rel rel
)
{
  // Precondition: readable_weak_range(first0, size0)
  // Precondition: readable_bounded_range(first1,last1)
  while (!zero(size0) && first1 != last1 && rel(*first0, *first1)) {
    size0 = predecessor(size0);
    first0 = successor(first0);
    first1 = successor(first1);
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
  while (first0 != last0 && !zero(size1) && rel(*first0, *first1)) {
    size1 = predecessor(size1);
    first0 = successor(first0);
    first1 = successor(first1);
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
  while (!zero(size0) && !zero(size1) && rel(*first0, *first1)) {
    size0 = predecessor(size0);
    size1 = predecessor(size1);
    first0 = successor(first0);
    first1 = successor(first1);
  }
  return std::make_tuple(first0, size0, first1, size1);
}

template<ReadableIterator I, IterRelation<I> Rel>
auto find_adjacent_mismatch_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (zero(size)) {
    return std::make_pair(first, size);
  }

  auto crnt = *first;
  first = successor(first);
  size = predecessor(size);
  while (!zero(size) && rel(crnt, *first)) {
    crnt = *first;
    size = predecessor(size);
    first = successor(first);
  }

  return std::make_pair(first, size);
}

template<ReadableIterator I, IterRelation<I> Rel>
bool relation_preserving_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return find_adjacent_mismatch_n(first, size, rel).second == 0;
}

template<ReadableIterator I, IterRelation<I> Rel>
bool strictly_increasing_range_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return relation_preserving_n(first, size, rel);
}

template<ReadableIterator I, IterRelation<I> Rel>
bool increasing_range_n(I first, iter_dist_t<I> size, Rel rel)
{
  // Precondition: readable_bounded_range(first, size)
  // Precondition: weak_ordering(rel);
  return relation_preserving_n(
      first, size, complement_of_converse<iter_value_t<I>>(rel)
  );
}

/* ----- Sentinel Ranges ----- */

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if_unguarded(I first, Pred pred)
{
  // Precondition: readable_bounded_range(first, last) && some(f, d, p);
  while (!pred(*first)) {
    first = successor(first);
  }
  return first;
}

template<ReadableIterator I, IterUnaryPredicate<I> Pred>
I find_if_not_unguarded(I first, Pred pred)
{
  // Precondition: readable_bounded_range(first, last) && not_all(f, d, p);
  while (pred(*first)) {
    first = successor(first);
  }
  return first;
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I find_adjacent_mismatch_forward(I first, I last, Rel rel)
{
  // Precondition: readable_bounded_range(first, last)

  if (first == last) {
    return last;
  }

  I tmp;
  do {
    tmp = first;
    first = successor(first);
  } while (first != last && rel(*tmp, *first));

  return first;
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
bool partitioned_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_bounded_range(first, size)
  std::tie(first, size) = find_if_n(first, size, pred);
  return find_if_not_n(first, size, pred).second == 0;
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
I partition_point_n(I first, iter_dist_t<I> size, Pred pred)
{
  // Precondition: readable_bounded_range(first, size)
  assert(partitioned_n(first, size, pred));

  while (!zero(size)) {
    const auto hlf = half(size);
    I mid = first + hlf;
    if (pred(*mid)) {
      size = hlf;
    } else {
      size -= successor(hlf);
      first = successor(mid);
    }
  }
  return first;
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I lower_bound_n(
    I first, iter_dist_t<I> size, const iter_value_t<I>& val, Rel rel
)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range_n(first, size, rel));

  return partition_point_n(first, size, lower_bound_predicate(val, rel));
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I upper_bound_n(
    I first, iter_dist_t<I> size, const iter_value_t<I>& val, Rel rel
)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range_n(first, size, rel));

  return partition_point_n(first, size, upper_bound_predicate(val, rel));
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
bool partitioned(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last)
  return find_if_not(find_if(first, last, pred), last, pred) == last;
}

template<ReadableForwardIterator I, IterUnaryPredicate<I> Pred>
I partition_point(I first, I last, Pred pred)
{
  // Precondition: readable_bounded_range(first, last)
  assert(partitioned(first, last, pred));

  return partition_point_n(first, last - first, pred);
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I lower_bound(I first, I last, const iter_value_t<I>& val, Rel rel)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range(first, last, rel));

  return based::lower_bound_n(first, last - first, val, rel);
}

template<ReadableForwardIterator I, IterRelation<I> Rel>
I upper_bound(I first, I last, const iter_value_t<I>& val, Rel rel)
{
  // Precondition: weak_ordering(rel)
  assert(increasing_range(first, last, rel));

  return based::upper_bound_n(first, last - first, val, rel);
}

}  // namespace based
