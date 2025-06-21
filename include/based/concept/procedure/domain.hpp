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

namespace based::trait
{

template<class T>
concept IsInput = IsSame<T, RemoveCvref<RemovePointer<T>>>
    || IsConst<RemoveReference<T>> || IsConst<RemovePointer<T>>;

template<SizeT idx, class... Args>
  requires(idx < sizeof...(Args))
using ElemT = std::tuple_element_t<idx, std::tuple<Args...>>;

template<class... Args>
concept IsDomainSemiregular = (IsSemiregular<RemoveCvref<Args>> && ...);

template<class... Args>
concept IsDomainRegular = (IsRegular<RemoveCvref<Args>> && ...);

template<class... Args>
concept IsDomainInput = (IsInput<Args> && ...);

template<class... Args>
concept IsDomainHomogeneous = (IsSame<ElemT<0, Args...>, Args> && ...);

template<class P, class... Args>
using RetT = InvokeResult<P, Args...>;

}  // namespace based::trait
