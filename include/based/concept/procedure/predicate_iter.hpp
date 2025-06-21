#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/predicate.hpp"

namespace based::trait
{

template<class P, class... I>
concept IsPredicateIter = requires {
  requires(IsIterator<I> && ...);
  requires(IsPredicate<P, IterValueT<I>...>);
};

template<class P, class... I>
concept IsPredicateHomogeneousIter = requires {
  requires(IsIterator<I> && ...);
  requires(IsPredicateHomogeneous<P, IterValueT<I>...>);
};

template<class P, class I>
concept IsPredicateUnaryIter = requires {
  requires(IsIterator<I>);
  requires(IsPredicateUnary<P, IterValueT<I>>);
};

template<class P, class I>
concept IsRelationIter = requires {
  requires(IsIterator<I>);
  requires(IsRelation<P, IterValueT<I>>);
};

}  // namespace based::trait
