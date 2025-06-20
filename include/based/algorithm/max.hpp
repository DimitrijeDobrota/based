#pragma once

#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/concept/procedure/procedure.hpp"
#include "based/trait/remove_reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

// returns max element, second if equal
template<
    trait::BareRegular T,
    trait::BareRegular U,
    RegularProcedure<bool, T, T> Rel>
  requires trait::IsSameBare<T, U>
constexpr decltype(auto) max(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? based::forward<T>(lhs) : based::forward<U>(rhs);
}

// returns max element, second if equal
template<trait::BareRegular T, trait::BareRegular U>
  requires trait::IsSameBare<T, U>
constexpr decltype(auto) max(T&& lhs, U&& rhs)
{
  return based::max(
      based::forward<T>(lhs),
      based::forward<U>(rhs),
      [](const trait::RemoveReference<T>& llhs,
         const trait::RemoveReference<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
