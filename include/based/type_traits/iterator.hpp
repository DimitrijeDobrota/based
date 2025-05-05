#pragma once

#include <iterator>

#include "based/types/types.hpp"

namespace based
{

namespace detail
{
template<typename I>
struct iterator_traits
{
  using value_type = I;
  using distance_type = u64;
  using pointer_type = I&;
  using reference_type = I*;
};

template<typename I>
  requires std::input_or_output_iterator<I>
struct iterator_traits<I>
{
  using value_type = std::iterator_traits<I>::value_type;
  using distance_type = std::iterator_traits<I>::difference_type;
  using pointer_type = std::iterator_traits<I>::pointer;
  using reference_type = std::iterator_traits<I>::reference;
};

}  // namespace detail

template<typename T>
using iter_value_t = detail::iterator_traits<T>::value_type;

template<typename T>
using iter_dist_t = detail::iterator_traits<T>::distance_type;

template<typename T>
using iter_ptr_t = detail::iterator_traits<T>::pointer;

template<typename T>
using iter_ref_t = detail::iterator_traits<T>::reference;

}  // namespace based
