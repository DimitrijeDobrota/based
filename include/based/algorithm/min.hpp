#pragma once

#include "based/concept/is/regular.hpp"
#include "based/concept/is/same.hpp"
#include "based/concept/procedure/procedure.hpp"
#include "based/trait/remove/reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

template<BareRegular T, BareRegular U, RegularProcedure<bool, T, T> Rel>
  requires BareSameAs<T, U>
constexpr decltype(auto) min(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? based::forward<U>(rhs) : based::forward<T>(lhs);
}

// returns min element, first if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
constexpr decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
      based::forward<T>(lhs),
      based::forward<U>(rhs),
      [](const remove_reference_t<T>& llhs, const remove_reference_t<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
