#pragma once

#include <cassert>

#include "based/type_traits.hpp"

namespace based
{

template<Transformation F>
distance_t<F> distance(domain_t<F> x, domain_t<F> y, F f)
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

template<Transformation F>
domain_t<F> convergant_point(domain_t<F> x0, domain_t<F> x1, F f)
{
  // Precondition: (exists n from distance_t<F>) n>= 0 ^ f^n(x0) = f^n(x1)
  while (x0 != x1) {
    x0 = f(x0);
    x1 = f(x1);
  }
  return x0;
}

template<Transformation F, TransformUnaryPredicate<F> P>
domain_t<F> collision_point(const domain_t<F>& x, F f, P p)
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

template<Transformation F, TransformUnaryPredicate<F> P>
bool terminating(const domain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  return !p(collision_point(x, f, p));
}

template<Transformation F, TransformUnaryPredicate<F> P>
bool circular(const domain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  return p(y) && x == f(y);
}

template<Transformation F, TransformUnaryPredicate<F> P>
bool connection_point(const domain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  if (!p(y)) {
    return y;
  }
  return convergant_point(x, f(y), f);
}

template<Transformation F, TransformUnaryPredicate<F> P>
std::tuple<distance_t<F>, distance_t<F>, domain_t<F>> orbit_structure(
    const domain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = connection_point(x, f, p);
  const auto m = distance(x, y, f);
  const auto n = p(y) ? distance(f(y), y, f) : 0;
  return {m, n, y};
}

template<Transformation F>
domain_t<F> collision_point_nonterminating_orbit(const domain_t<F>& x, F f)
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

template<Transformation F>
bool circular_nonterminating_orbit(const domain_t<F>& x, F f)
{
  return x == f(collision_point_nonterminating_orbit(x, f));
}

template<Transformation F>
domain_t<F> connection_point_nonterminating_orbit(const domain_t<F>& x, F f)
{
  return convergant_point(x, f(collision_point_nonterminating_orbit(x, f)), f);
}

template<Transformation F>
std::tuple<distance_t<F>, distance_t<F>, domain_t<F>>
orbit_structure_nonterminating_orbit(const domain_t<F>& x, F f)
{
  const auto y = connection_point_nonterminating_orbit(x, f);
  return {distance(x, y, f), distance(f(y), y, f), y};
}

template<Transformation F, Integer N>
domain_t<F> power_unary(domain_t<F> x, N n, F f)
{
  while (!zero(n)) {
    n = predecessor(n);
    x = f(x);
  }
  return x;
}

template<Integer I, BinaryOperation Op>
domain_t<Op> power_left_associated(domain_t<Op> a, I n, Op op)
{
  assert(n > 0);
  return one(n) ? a : op(power_left_associated(a, predecessor(n), op), a);
}

template<Integer I, BinaryOperation Op>
domain_t<Op> power_right_associated(domain_t<Op> a, I n, Op op)
{
  assert(n > 0);
  return one(n) ? a : op(a, power_right_associated(a, predecessor(n), op));
}

template<Integer I, AssociativeBinaryOperation Op>
domain_t<Op> power_accumulate_positive(domain_t<Op> r,
                                       domain_t<Op> a,
                                       I n,
                                       Op op)
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

template<Integer I, AssociativeBinaryOperation Op>
domain_t<Op> power_accumulate(domain_t<Op> r, domain_t<Op> a, I n, Op op)
{
  assert(n >= 0);
  return zero(n) ? r : power_accumulate_positive(r, a, n, op);
}

template<Integer I, AssociativeBinaryOperation Op>
domain_t<Op> power(domain_t<Op> a, I n, Op op)
{
  assert(n > 0);
  while (even(n)) {
    a = op(a, a);
    n = half(n);
  }

  n = half(n);
  return zero(n) ? a : power_accumulate_positive(a, op(a, a), n, op);
}

template<Integer I, AssociativeBinaryOperation Op>
domain_t<Op> power(domain_t<Op> a, I n, Op op, domain_t<Op> id)
{
  assert(n >= 0);
  return !zero(n) ? power(a, n, op) : id;
}

template<Integer I>
std::pair<I, I> fibonacci_matrix_multiply(const std::pair<I, I>& x,
                                          const std::pair<I, I>& y)
{
  return {(x.first * (y.first + y.second)) + (x.second * y.first),
          (x.first * y.first) + (x.second * y.second)};
}

template<Integer I>
I fibonacci(I n)
{
  assert(n >= 0);
  return !zero(n) ? power({I {1}, I {0}}, n, fibonacci_matrix_multiply<I>).first
                  : I {0};
}

template<Relation R>
auto complement(R r)
{
  return [r](const domain_t<R>& a, const domain_t<R>& b) { return !r(a, b); };
}

template<Relation R>
auto converse(R r)
{
  return [r](const domain_t<R>& a, const domain_t<R>& b) { return r(b, a); };
}

template<Relation R>
auto complement_of_converse(R r)
{
  return [r](const domain_t<R>& a, const domain_t<R>& b) { return !r(b, a); };
}

}  // namespace based
