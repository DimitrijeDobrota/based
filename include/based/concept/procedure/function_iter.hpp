#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/function.hpp"

namespace based::trait
{

template<class P, class Ret, class I>
concept IsProcedureFunctionalIter = requires {
  requires(IsIterator<I>);
  requires(IsProcedureFunctional<P, Ret, IterValueT<I>>);
};

template<class P, class Ret, class I>
concept IsFunctionUnaryIter = requires {
  requires(IsIterator<I>);
  requires(IsFunctionUnary<P, Ret, IterValueT<I>>);
};

template<class P, class Ret, class I>
concept IsFunctionHomogeneousIter = requires {
  requires(IsIterator<I>);
  requires(IsFunctionHomogeneous<P, Ret, IterValueT<I>>);
};

}  // namespace based::trait
