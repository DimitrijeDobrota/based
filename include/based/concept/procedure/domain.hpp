#pragma once

#include <tuple>

#include "based/concept/is/regular.hpp"
#include "based/concept/is/same.hpp"
#include "based/concept/is/semiregular.hpp"
#include "based/integral/types.hpp"
#include "based/trait/invoke_result.hpp"
#include "based/trait/is/const.hpp"
#include "based/trait/remove/cvref.hpp"
#include "based/trait/remove/pointer.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

template<typename T>
concept Input = SameAs<T, RemoveCvrefT<RemovePointerT<T>>>
    || is_const_v<RemoveReferenceT<T>> || is_const_v<RemovePointerT<T>>;

template<SizeT idx, typename... Args>
  requires(idx < sizeof...(Args))
using ElemT = std::tuple_element_t<idx, std::tuple<Args...>>;

template<typename... Args>
concept SemiregularDomain = (Semiregular<RemoveCvrefT<Args>> && ...);

template<typename... Args>
concept RegularDomain = (Regular<RemoveCvrefT<Args>> && ...);

template<typename... Args>
concept InputDomain = (Input<Args> && ...);

template<typename... Args>
concept HomogeneousDomain = (SameAs<ElemT<0, Args...>, Args> && ...);

template<typename P, typename... Args>
using RetT = InvokeResultT<P, Args...>;

}  // namespace based
