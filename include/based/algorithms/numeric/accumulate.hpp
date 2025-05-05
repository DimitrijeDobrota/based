#pragma once

#include <cassert>

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/operation.hpp"

namespace based
{

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto accumulate_nonempty(I first, I last, Op opr, F fun)
{
  assert(first != last);
  // Precondition: bounded_range(first, last)
  // Precondition: partially_associative(opr)

  auto res = fun(first);
  first++;
  while (first != last) {
    res = opr(res, fun(first));
    first++;
  }
  return res;
}

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto accumulate(
    I first,
    I last,
    Op opr,
    F fun,
    const decltype(accumulate_nonempty(first, last, opr, fun))& zero
)
{
  // Precondition: bounded_range(first, last)
  // Precondition: partially_associative(opr)
  if (first == last) {
    return zero;
  }
  return accumulate_nonempty(first, last, opr, fun);
}

template<Iterator I, UnaryFunction<void, I> F, BinaryOperation<ret_t<F, I>> Op>
auto accumulate_nonzero(
    I first,
    I last,
    Op opr,
    F fun,
    const decltype(accumulate_nonempty(first, last, opr, fun))& zero
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
    first++;
  } while (res == zero);

  while (first != last) {
    auto crnt = fun(first);
    if (crnt != zero) {
      res = opr(res, crnt);
    }
    first++;
  }
  return res;
}

}  // namespace based
