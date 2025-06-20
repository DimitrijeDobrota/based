#pragma once

#include <iterator>

#include "based/integral/types.hpp"

namespace based
{

namespace detail
{
template<typename I>
struct IteratorTraits
{
  using value_type = I;
  using distance_type = u64;
  using PointerType = I&;
  using ReferenceType = I*;
};

template<typename I>
  requires std::input_or_output_iterator<I>
struct IteratorTraits<I>
{
  using value_type = std::iterator_traits<I>::value_type;
  using DistanceType = std::iterator_traits<I>::difference_type;
  using PointerType = std::iterator_traits<I>::pointer;
  using ReferenceType = std::iterator_traits<I>::reference;
};

}  // namespace detail

template<typename T>
using IterValueT = detail::IteratorTraits<T>::value_type;

template<typename T>
using IterDistT = detail::IteratorTraits<T>::distance_type;

template<typename T>
using IterPtrT = detail::IteratorTraits<T>::pointer;

template<typename T>
using IterRefT = detail::IteratorTraits<T>::reference;

}  // namespace based
