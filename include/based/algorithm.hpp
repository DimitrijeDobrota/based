#pragma once

#include <functional>
#include <utility>

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

template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
      std::forward<T>(lhs), std::forward<U>(rhs), std::less<bare_t<T>>());
}

// return first min element
template<RegularIterator I, Relation R>
  requires std::same_as<typename I::value_type, domain_t<R>>
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

template<RegularIterator I>
I min_element(I first, I last)
{
  return based::min_element(first, last, std::less<typename I::value_type>());
}

// returns max element, second if equal
template<Relation R>
const domain_t<R>& max(const domain_t<R>& lhs, const domain_t<R>& rhs, R r)
{
  return r(rhs, lhs) ? lhs : rhs;
}

template<Regular T>
const T& max(const T& lhs, const T& rhs)
{
  return based::max(lhs, rhs, std::less<T>());
}

// return last max element
template<RegularIterator I, Relation R>
  requires std::same_as<typename I::value_type, domain_t<R>>
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

template<RegularIterator I>
I max_element(I first, I last)
{
  return based::max_element(first, last, std::less<typename I::value_type>());
}

// return first min and last max element
template<RegularIterator I, Relation R>
  requires std::same_as<typename I::value_type, domain_t<R>>
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

  I next = std::next(first);
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

template<RegularIterator I>
std::pair<I, I> minmax_element(I first, I last)
{
  return based::minmax_element(
      first, last, std::less<typename I::value_type>());
}

}  // namespace based
