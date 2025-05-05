#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/predicate.hpp"

namespace based
{

template<typename P, typename... I>
concept IterPredicate = requires {
  requires(Iterator<I> && ...);
  requires(Predicate<P, iter_value_t<I>...>);
};

template<typename P, typename... I>
concept IterHomogeneousPredicate = requires {
  requires(Iterator<I> && ...);
  requires(HomogeneousPredicate<P, iter_value_t<I>...>);
};

template<typename P, typename I>
concept IterUnaryPredicate = requires {
  requires(Iterator<I>);
  requires(UnaryPredicate<P, iter_value_t<I>>);
};

template<typename P, typename I>
concept IterRelation = requires {
  requires(Iterator<I>);
  requires(Relation<P, iter_value_t<I>>);
};

}  // namespace based
