#pragma once

#include "based/concept/procedure/domain.hpp"
#include "based/concept/procedure/procedure.hpp"

namespace based
{

template<typename P, typename Ret, typename... Args>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P, Ret, Args...>);
  requires(InputDomain<Args...>);
};

template<typename P, typename Ret, typename Arg>
concept UnaryFunction = requires {
  requires(FunctionalProcedure<P, Ret, Arg>);
  requires(UnaryProcedure<P, Ret, Arg>);
};

template<typename P, typename Ret, typename... Args>
concept HomogeneousFunction = requires {
  requires(FunctionalProcedure<P, Ret, Args...>);
  requires(sizeof...(Args) > 0);
  requires(HomogeneousDomain<Args...>);
};

}  // namespace based
