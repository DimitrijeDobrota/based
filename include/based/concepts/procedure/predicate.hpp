#pragma once

#include "based/concepts/procedure/function.hpp"

namespace based
{

template<typename P, typename... Args>
concept Predicate = FunctionalProcedure<P, bool, Args...>;

template<typename P, typename... Args>
concept HomogeneousPredicate = requires {
  requires(Predicate<P, Args...>);
  requires(HomogeneousFunction<P, bool, Args...>);
};

template<typename P, typename Arg>
concept UnaryPredicate = requires {
  requires(Predicate<P, Arg>);
  requires(UnaryFunction<P, bool, Arg>);
};

template<typename P, typename Arg>
concept Relation = HomogeneousPredicate<P, Arg, Arg>;

}  // namespace based
