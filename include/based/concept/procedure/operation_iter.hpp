#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/operation.hpp"

namespace based::trait
{

template<class P, class Ret, class... I>
concept IsOperationIter = requires {
  requires(IsIterator<I> && ...);
  requires(IsOperation<P, IterValueT<I>...>);
};

template<class P, class Ret, class I>
concept IsBinaryOperationIter = requires {
  requires(IsIterator<I>);
  requires(IsOperationBinary<P, IterValueT<I>>);
};

}  // namespace based::trait
