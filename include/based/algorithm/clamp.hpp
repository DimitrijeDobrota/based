#pragma once

#include "based/algorithm/max.hpp"
#include "based/algorithm/min.hpp"
#include "based/concept/is_regular.hpp"
#include "based/concept/is_same.hpp"
#include "based/concept/procedure/procedure.hpp"
#include "based/trait/remove_reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

// clamp a value between low and high
template<
    trait::IsRegularBare                  T,
    trait::IsRegularBare                  U,
    trait::IsRegularBare                  V,
    trait::IsProcedureRegular<bool, T, T> Rel>
  requires(trait::IsSameBare<T, U> && trait::IsSameBare<T, V>)
constexpr decltype(auto) clamp(T&& value, U&& low, V&& high, Rel rel)
{
  return based::max(
      based::forward<U>(low),
      based::min(based::forward<V>(high), based::forward<T>(value), rel),
      rel
  );
}

// clamp a value between low and high
template<trait::IsRegularBare T, trait::IsRegularBare U, trait::IsRegularBare V>
  requires(trait::IsSameBare<T, U> && trait::IsSameBare<T, V>)
constexpr decltype(auto) clamp(T&& value, U&& low, V&& high)
{
  return based::clamp(
      based::forward<T>(value),
      based::forward<U>(low),
      based::forward<V>(high),
      [](const trait::RemoveReference<T>& llhs,
         const trait::RemoveReference<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
