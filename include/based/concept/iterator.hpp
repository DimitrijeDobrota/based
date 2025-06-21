#pragma once

#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/trait/iterator.hpp"

namespace based::trait
{

// clang-format off

template<class T>
concept IsReadable = requires(T val) {
  requires(IsRegular<T>);
  typename IterValueT<T>;
  {
    *val
  } -> IsSameBare<IterValueT<T>>;
};

template<class T>
concept IsIterator = requires(T val) {
  requires(IsRegular<T>);
  typename IterDistT<T>;
  {
    ++val
  } -> IsSameBare<T>;
  // successor is not necessarily regular
};

template<class T>
concept IsIteratorForward = requires {
  requires(IsIterator<T>);
  // successor is regular
};

template<class T>
concept IsIteratorReadable = requires {
  requires(IsIterator<T>);
  requires(IsReadable<T>);
};

template<class T>
concept IsIteratorForwardReadable = requires {
  requires(IsIteratorForward<T>);
  requires(IsReadable<T>);
};

// clang-format on

}  // namespace based::trait
