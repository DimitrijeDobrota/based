#pragma once

#include "based/concept/procedure/function.hpp"

namespace based::trait
{

template<class P, class... Args>
concept IsPredicate = IsProcedureFunctional<P, bool, Args...>;

template<class P, class... Args>
concept IsPredicateHomogeneous = requires {
  requires(IsPredicate<P, Args...>);
  requires(IsFunctionHomogeneous<P, bool, Args...>);
};

template<class P, class Arg>
concept IsPredicateUnary = requires {
  requires(IsPredicate<P, Arg>);
  requires(IsFunctionUnary<P, bool, Arg>);
};

template<class P, class Arg>
concept IsRelation = IsPredicateHomogeneous<P, Arg, Arg>;

}  // namespace based::trait
