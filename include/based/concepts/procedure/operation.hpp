#pragma once

#include "based/concepts/procedure/function.hpp"

namespace based
{

template<typename P, typename... Args>
concept Operation = HomogeneousFunction<P, elem_t<0, Args...>, Args...>;

template<typename P, typename Ret, typename Arg>
concept Transformation = requires {
  requires(Operation<P, Ret, Arg>);
  requires(UnaryFunction<P, Ret, Arg>);
};

template<typename P, typename Arg>
concept BinaryOperation = Operation<P, Arg, Arg>;

template<typename P, typename Arg>
concept AssociativeBinaryOperation = Operation<P, Arg, Arg>;

}  // namespace based
