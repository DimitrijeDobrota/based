#pragma once

#include "based/concept/iterator.hpp"
#include "based/concept/procedure/procedure.hpp"

namespace based
{

template<typename P, typename Ret, typename I>
concept IterProcedure = requires {
  requires(Iterator<I>);
  requires(Procedure<P, Ret, iter_value_t<I>>);
};

template<typename P, typename Ret, typename I>
concept IterUnaryProcedure = requires {
  requires(Iterator<I>);
  requires(UnaryProcedure<P, Ret, iter_value_t<I>>);
};

template<typename P, typename Ret, typename I>
concept Itertrait::RegularProcedure = requires {
  requires(Iterator<I>);
  requires(trait::RegularProcedure<P, Ret, iter_value_t<I>>);
};

}  // namespace based
