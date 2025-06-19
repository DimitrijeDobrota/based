#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/function.hpp"

namespace based
{

template<typename P, typename Ret, typename I>
concept IterFunctionalProcedure = requires {
  requires(Iterator<I>);
  requires(FunctionalProcedure<P, Ret, iter_value_t<I>>);
};

template<typename P, typename Ret, typename I>
concept IterUnaryFunction = requires {
  requires(Iterator<I>);
  requires(UnaryFunction<P, Ret, iter_value_t<I>>);
};

template<typename P, typename Ret, typename I>
concept IterHomogeneousFunction = requires {
  requires(Iterator<I>);
  requires(HomogeneousFunction<P, Ret, iter_value_t<I>>);
};

}  // namespace based
