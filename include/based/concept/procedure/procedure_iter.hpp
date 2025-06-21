#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/procedure.hpp"

namespace based::trait
{

template<class P, class Ret, class I>
concept IsProcedureIter = requires {
  requires(IsIterator<I>);
  requires(IsProcedure<P, Ret, IterValueT<I>>);
};

template<class P, class Ret, class I>
concept IsProcedureUnaryIter = requires {
  requires(IsIterator<I>);
  requires(IsProcedureUnary<P, Ret, IterValueT<I>>);
};

template<class P, class Ret, class I>
concept IsProcedureRegularIter = requires {
  requires(IsIterator<I>);
  requires(trait::IsProcedureRegular<P, Ret, IterValueT<I>>);
};

}  // namespace based::trait
