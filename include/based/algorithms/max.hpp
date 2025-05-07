#pragma once

#include "based/concepts/is/regular.hpp"
#include "based/concepts/is/same.hpp"
#include "based/concepts/procedure/procedure.hpp"
#include "based/trait/remove/reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

namespace detail
{

template<typename P, typename Arg>
concept NoninputRelation = RegularProcedure<P, bool, Arg, Arg>;

}  // namespace detail

// returns max element, second if equal
template<BareRegular T, BareRegular U, detail::NoninputRelation<T> Rel>
  requires BareSameAs<T, U>
decltype(auto) max(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? based::forward<T>(lhs) : based::forward<U>(rhs);
}

// returns max element, second if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) max(T&& lhs, U&& rhs)
{
  return based::max(
      based::forward<T>(lhs),
      based::forward<U>(rhs),
      [](const remove_reference_t<T>& llhs, const remove_reference_t<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
