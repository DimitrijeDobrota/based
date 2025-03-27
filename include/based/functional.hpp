#pragma once

#include "based/type_traits.hpp"

namespace based
{

template<Transformation F>
distance_t<F> distance(codomain_t<F> x, codomain_t<F> y, F f)
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
codomain_t<F> convergant_point(codomain_t<F> x0, codomain_t<F> x1, F f)
{
  // Precondition: (exists n from distance_t<F>) n>= 0 ^ f^n(x0) = f^n(x1)
  while (x0 != x1) {
    x0 = f(x0);
    x1 = f(x1);
  }
  return x0;
}

template<Transformation F, UnaryPredicate P>
  requires SameAs<domain_t<F>, domain_t<P>>
codomain_t<F> collision_point(const codomain_t<F>& x, F f, P p)
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

template<Transformation F, UnaryPredicate P>
  requires SameAs<domain_t<F>, domain_t<P>>
bool terminating(const codomain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  return !p(collision_point(x, f, p));
}

template<Transformation F, UnaryPredicate P>
  requires SameAs<domain_t<F>, domain_t<P>>
bool circular(const codomain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  return p(y) && x == f(y);
}

template<Transformation F, UnaryPredicate P>
  requires SameAs<domain_t<F>, domain_t<P>>
bool connection_point(const codomain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = collision_point(x, f, p);
  if (!p(y)) {
    return y;
  }
  return convergant_point(x, f(y), f);
}

template<Transformation F, UnaryPredicate P>
  requires SameAs<domain_t<F>, domain_t<P>>
std::tuple<distance_t<F>, distance_t<F>, domain_t<F>> orbit_structure(
    const codomain_t<F>& x, F f, P p)
{
  // Precondition: p(x) <=> F(x) is defined
  const auto y = connection_point(x, f, p);
  const auto m = distance(x, y, f);
  const auto n = p(y) ? distance(f(y), y, f) : 0;
  return {m, n, y};
}

template<Transformation F>
codomain_t<F> collision_point_nonterminating_orbit(const codomain_t<F>& x, F f)
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
bool circular_nonterminating_orbit(const codomain_t<F>& x, F f)
{
  return x == f(collision_point_nonterminating_orbit(x, f));
}

template<Transformation F>
codomain_t<F> connection_point_nonterminating_orbit(const codomain_t<F>& x, F f)
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
codomain_t<F> power_unary(codomain_t<F> x, N n, F f)
{
  while (n != N {0}) {
    n = n - N {1};
    x = f(x);
  }
  return x;
}

}  // namespace based
