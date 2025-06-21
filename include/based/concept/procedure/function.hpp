#pragma once

#include "based/concept/procedure/domain.hpp"
#include "based/concept/procedure/procedure.hpp"

namespace based::trait
{

template<class P, class Ret, class... Args>
concept IsProcedureFunctional = requires {
  requires(IsProcedureRegular<P, Ret, Args...>);
  requires(IsDomainInput<Args...>);
};

template<class P, class Ret, class Arg>
concept IsFunctionUnary = requires {
  requires(IsProcedureFunctional<P, Ret, Arg>);
  requires(IsProcedureUnary<P, Ret, Arg>);
};

template<class P, class Ret, class... Args>
concept IsFunctionHomogeneous = requires {
  requires(IsProcedureFunctional<P, Ret, Args...>);
  requires(sizeof...(Args) > 0);
  requires(IsDomainHomogeneous<Args...>);
};

}  // namespace based::trait
