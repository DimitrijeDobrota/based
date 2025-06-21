#pragma once

#include "based/concept/procedure/function.hpp"

namespace based::trait
{

template<class P, class... Args>
concept IsOperation = IsFunctionHomogeneous<P, ElemT<0, Args...>, Args...>;

template<class P, class Ret, class Arg>
concept IsTransformation = requires {
  requires(IsOperation<P, Ret, Arg>);
  requires(IsFunctionUnary<P, Ret, Arg>);
};

template<class P, class Arg>
concept IsOperationBinary = IsOperation<P, Arg, Arg>;

}  // namespace based::trait
