#pragma once

#include "based/concepts/iterator.hpp"
#include "based/concepts/procedure/operation.hpp"

namespace based
{

template<typename P, typename Ret, typename... I>
concept IterOperation = requires {
  requires(Iterator<I> && ...);
  requires(Operation<P, iter_value_t<I>...>);
};

template<typename P, typename Ret, typename I>
concept IterBinaryOperation = requires {
  requires(Iterator<I>);
  requires(BinaryOperation<P, iter_value_t<I>>);
};

}  // namespace based
