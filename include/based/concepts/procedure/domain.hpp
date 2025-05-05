#pragma once

#include <tuple>

#include "based/concepts/is/regular.hpp"
#include "based/concepts/is/same.hpp"
#include "based/concepts/is/semiregular.hpp"
#include "based/type_traits/is/const.hpp"
#include "based/type_traits/remove/cvref.hpp"
#include "based/type_traits/remove/pointer.hpp"
#include "based/type_traits/remove/reference.hpp"
#include "based/types/types.hpp"

namespace based
{

template<typename T>
concept Input = SameAs<T, remove_cvref_t<remove_pointer_t<T>>>
    || is_const_v<remove_reference_t<T>> || is_const_v<remove_pointer_t<T>>;

template<size_t idx, typename... Args>
  requires(idx < sizeof...(Args))
using elem_t = std::tuple_element_t<idx, std::tuple<Args...>>;

template<typename... Args>
concept SemiregularDomain = (Semiregular<remove_cvref_t<Args>> && ...);

template<typename... Args>
concept RegularDomain = (Regular<remove_cvref_t<Args>> && ...);

template<typename... Args>
concept InputDomain = (Input<Args> && ...);

template<typename... Args>
concept HomogeneousDomain = (SameAs<elem_t<0, Args...>, Args> && ...);

template<typename P, typename... Args>
using ret_t = std::invoke_result_t<P, Args...>;

}  // namespace based
