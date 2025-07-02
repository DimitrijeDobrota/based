#pragma once

#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/concept/procedure/procedure.hpp"
#include "based/trait/remove_reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

template<
    trait::IsRegularBare                  T,
    trait::IsRegularBare                  U,
    trait::IsProcedureRegular<bool, T, T> Rel>
  requires trait::IsSameBare<T, U>
constexpr decltype(auto) min(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? based::forward<U>(rhs) : based::forward<T>(lhs);
}

// returns min element, first if equal
template<trait::IsRegularBare T, trait::IsRegularBare U>
  requires trait::IsSameBare<T, U>
constexpr decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
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
