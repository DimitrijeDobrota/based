#pragma once

#include <functional>
#include <utility>

namespace based
{

// need to deal with returned reference to temporary object...

// returns min element, first if equal
template<typename T, typename Cmp>
const T& min(const T& lhs, const T& rhs, Cmp cmp)
{
  return cmp(rhs, lhs) ? rhs : lhs;
}

template<typename T>
const T& min(const T& lhs, const T& rhs)
{
  return based::min(lhs, rhs, std::less());
}

// return first min element
template<typename I, typename Cmp>
I min_element(I first, I last, Cmp cmp)
{
  if (first == last) {
    return last;
  }

  I mini = first++;
  while (first != last) {
    if (cmp(*first, *mini)) {
      mini = first;
    }
    first++;
  }
  return mini;
}

template<typename I>
I min_element(I first, I last)
{
  return based::min_element(first, last, std::less());
}

// returns max element, second if equal
template<typename T, typename Cmp>
const T& max(const T& lhs, const T& rhs, Cmp cmp)
{
  return cmp(rhs, lhs) ? lhs : rhs;
}

template<typename T>
const T& max(const T& lhs, const T& rhs)
{
  return based::max(lhs, rhs, std::less());
}

// return last max element
template<typename I, typename Cmp>
I max_element(I first, I last, Cmp cmp)
{
  if (first == last) {
    return last;
  }

  I maxi = first++;
  while (first != last) {
    if (!cmp(*first, *maxi)) {
      maxi = first;
    }
    first++;
  }
  return maxi;
}

template<typename I>
I max_element(I first, I last)
{
  return based::max_element(first, last, std::less());
}

// return first min and last max element
template<typename I, typename Cmp>
std::pair<I, I> minmax_element(I first, I last, Cmp cmp)
{
  if (first == last) {
    return {last, last};
  }

  I mini = first++;
  if (first == last) {
    return {mini, mini};
  }

  I maxi = first++;
  if (cmp(*maxi, *mini)) {
    std::swap(mini, maxi);
  }

  I next = std::next(first);
  while (first != last && next != last) {
    I pmini = first;
    I pmaxi = next;

    if (cmp(*pmaxi, *pmini)) {
      std::swap(pmini, pmaxi);
    }

    if (cmp(*pmini, *mini)) {
      mini = pmini;
    }

    if (!cmp(*pmaxi, *maxi)) {
      maxi = pmaxi;
    }

    next++;
    first = next;
    next++;
  }

  if (first != last) {
    if (cmp(*first, *mini)) {
      mini = first;
    } else if (!cmp(*first, *maxi)) {
      maxi = first;
    }
  }

  return {mini, maxi};
}

template<typename I>
std::pair<I, I> minmax_element(I first, I last)
{
  return based::minmax_element(first, last, std::less());
}

}  // namespace based
