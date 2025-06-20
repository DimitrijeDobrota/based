#pragma once

#include <tuple>

#include "based/concept/is_const.hpp"
#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/concept/is_semiregular.hpp"
#include "based/integral/types.hpp"
#include "based/trait/invoke_result.hpp"
#include "based/trait/remove_cvref.hpp"
#include "based/trait/remove_pointer.hpp"
#include "based/trait/remove_reference.hpp"

namespace based
{

template<typename T>
concept Input = trait::IsSame<T, trait::RemoveCvref<trait::RemovePointer<T>>>
    || trait::IsConst<trait::RemoveReference<T>>
    || trait::IsConst<trait::RemovePointer<T>>;

template<SizeT idx, typename... Args>
  requires(idx < sizeof...(Args))
using ElemT = std::tuple_element_t<idx, std::tuple<Args...>>;

template<typename... Args>
concept SemiregularDomain =
    (trait::Semiregular<trait::RemoveCvref<Args>> && ...);

template<typename... Args>
concept RegularDomain = (trait::Regular<trait::RemoveCvref<Args>> && ...);

template<typename... Args>
concept InputDomain = (Input<Args> && ...);

template<typename... Args>
concept HomogeneousDomain = (trait::IsSame<ElemT<0, Args...>, Args> && ...);

template<typename P, typename... Args>
using RetT = InvokeResultT<P, Args...>;

}  // namespace based
