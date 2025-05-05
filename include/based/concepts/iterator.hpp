#pragma once

#include "based/concepts/is/regular.hpp"
#include "based/concepts/is/same.hpp"
#include "based/type_traits/iterator.hpp"

namespace based
{

// clang-format off

template<typename T>
concept Readable = requires(T val) {
  requires(Regular<T>);
  typename iter_value_t<T>;
  {
    *val
  } -> BareSameAs<iter_value_t<T>>;
};

template<typename T>
concept Iterator = requires(T val) {
  requires(Regular<T>);
  typename iter_dist_t<T>;
  {
    ++val
  } -> BareSameAs<T>;
  // successor is not necessarily regular
};

template<typename T>
concept ForwardIterator = requires {
  requires(Iterator<T>);
  // successor is regular
};

template<typename T>
concept ReadableIterator = requires {
  requires(Iterator<T>);
  requires(Readable<T>);
};

template<typename T>
concept ReadableForwardIterator = requires {
  requires(ForwardIterator<T>);
  requires(Readable<T>);
};

// clang-format on

}  // namespace based
