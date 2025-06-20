#pragma once

#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/trait/iterator.hpp"

namespace based
{

// clang-format off

template<typename T>
concept Readable = requires(T val) {
  requires(trait::Regular<T>);
  typename iter_value_t<T>;
  {
    *val
  } -> trait::IsSameBare<iter_value_t<T>>;
};

template<typename T>
concept Iterator = requires(T val) {
  requires(trait::Regular<T>);
  typename iter_dist_t<T>;
  {
    ++val
  } -> trait::IsSameBare<T>;
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
