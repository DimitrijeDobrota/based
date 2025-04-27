#pragma once

#include <cassert>

#include "based/type_traits.hpp"

namespace based
{

template<typename T, Transformation<T> F>
distance_t<F> distance(T x, T y, F f)
{
  // Precondition: y is reachable from x under f
  using N = distance_t<F>;

  N n {0};
  while (x != y) {
    x = f(x);
    n = n + N {1};
  }
  return n;
}

template<typename T, Transformation<T> F>
T convergant_point(T x0, T x1, F f)
{
  // Precondition: (exists n from distance_t<F>) n>= 0 ^ f^n(x0) = f^n(x1)
  while (x0 != x1) {
    x0 = f(x0);
    x1 = f(x1);
  }
  return x0;
}

template<typename T, Transformation<T> F, UnaryPredicate<T> P>
T collision_point(const T& x, F f, P p)
{
  // Precondition p(x) <=> f(x) is defined
  if (!p(x)) {
    return x;
  }

  auto slow = x;
  auto fast = f(x);
  while (fast != slow) {
    slow = f(slow);
    if (!p(fast)) {
      return fast;
    }
    fast = f(fast);
    if (!p(fast)) {
      return fast;
    }
    fast = f(fast);
  }
  return fast;
  // Postcondition: return value is terminal point or collision point
}

template<typename T, Transformation<T> F, UnaryPredicate<T> P>
bool terminating(const T& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  return !p(collision_point(x, f, p));
}

template<typename T, Transformation<T> F, UnaryPredicate<T> P>
bool circular(const T& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  return p(y) && x == f(y);
}

template<typename T, Transformation<T> F, UnaryPredicate<T> P>
bool connection_point(const T& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  if (!p(y)) {
    return y;
  }
  return convergant_point(x, f(y), f);
}

template<typename T, Transformation<T> F, UnaryPredicate<T> P>
std::tuple<distance_t<F>, distance_t<F>, T> orbit_structure(
    const T& x, F f, P p
)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = connection_point(x, f, p);
  const auto m = distance(x, y, f);
  const auto n = p(y) ? distance(f(y), y, f) : 0;
  return {m, n, y};
}

template<typename T, Transformation<T> F>
T collision_point_nonterminating_orbit(const T& x, F f)
{
  auto slow = x;
  auto fast = f(x);
  while (fast != slow) {
    slow = f(slow);
    fast = f(fast);
    fast = f(fast);
  }
  return fast;
  // Postcondition: return value is terminal point or collision point
}

template<typename T, Transformation<T> F>
bool circular_nonterminating_orbit(const T& x, F f)
{
  return x == f(collision_point_nonterminating_orbit(x, f));
}

template<typename T, Transformation<T> F>
T connection_point_nonterminating_orbit(const T& x, F f)
{
  return convergant_point(x, f(collision_point_nonterminating_orbit(x, f)), f);
}

template<typename T, Transformation<T> F>
std::tuple<distance_t<F>, distance_t<F>, T>
orbit_structure_nonterminating_orbit(const T& x, F f)
{
  const auto y = connection_point_nonterminating_orbit(x, f);
  return {distance(x, y, f), distance(f(y), y, f), y};
}

template<typename T, Transformation<T> F, Integer N>
T power_unary(T x, N n, F f)
{
  while (!zero(n)) {
    n = predecessor(n);
    x = f(x);
  }
  return x;
}

template<typename T, Integer I, BinaryOperation<T> Op>
T power_left_associated(T a, I n, Op op)
{
  assert(n > 0);
  return one(n) ? a : op(power_left_associated(a, predecessor(n), op), a);
}

template<typename T, Integer I, BinaryOperation<T> Op>
T power_right_associated(T a, I n, Op op)
{
  assert(n > 0);
  return one(n) ? a : op(a, power_right_associated(a, predecessor(n), op));
}

template<typename T, Integer I, AssociativeBinaryOperation<T> Op>
T power_accumulate_positive(T r, T a, I n, Op op)
{
  assert(n > 0);
  while (true) {
    if (odd(n)) {
      r = op(r, a);
      if (one(n)) {
        return r;
      }
    }
    a = op(a, a);
    n = half(n);
  }
}

template<typename T, Integer I, AssociativeBinaryOperation<T> Op>
T power_accumulate(T r, T a, I n, Op op)
{
  assert(n >= 0);
  return zero(n) ? r : power_accumulate_positive(r, a, n, op);
}

template<typename T, Integer I, AssociativeBinaryOperation<T> Op>
T power(T a, I n, Op op)
{
  assert(n > 0);
  while (even(n)) {
    a = op(a, a);
    n = half(n);
  }

  n = half(n);
  return zero(n) ? a : power_accumulate_positive(a, op(a, a), n, op);
}

template<typename T, Integer I, AssociativeBinaryOperation<T> Op>
T power(T a, I n, Op op, T id)
{
  assert(n >= 0);
  return !zero(n) ? power(a, n, op) : id;
}

template<Integer I>
std::pair<I, I> fibonacci_matrix_multiply(
    const std::pair<I, I>& x, const std::pair<I, I>& y
)
{
  return {
      (x.first * (y.first + y.second)) + (x.second * y.first),
      (x.first * y.first) + (x.second * y.second)
  };
}

template<Integer I>
I fibonacci(I n)
{
  assert(n >= 0);
  return !zero(n)
      ? power<std::pair<I, I>>({I {1}, I {0}}, n, fibonacci_matrix_multiply<I>)
            .first
      : I {0};
}

template<typename T, Relation<T> R>
auto complement(R r)
{
  return [=](const T& a, const T& b)
  {
    return !r(a, b);
  };
}

template<typename T, Relation<T> R>
auto converse(R r)
{
  return [=](const T& a, const T& b)
  {
    return r(b, a);
  };
}

template<typename T, Relation<T> R>
auto complement_of_converse(R r)
{
  return [=](const T& a, const T& b)
  {
    return !r(b, a);
  };
}

template<typename T, Relation<T> R>
auto lower_bound_predicate(const T& a, R r)
{
  return [=](const T& x)
  {
    return !r(x, a);
  };
}

template<typename T, Relation<T> R>
auto upper_bound_predicate(const T& a, R r)
{
  return [=](const T& x)
  {
    return r(a, x);
  };
}

}  // namespace based
