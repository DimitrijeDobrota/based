#pragma once

#include <functional>

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

}  // namespace based
