#pragma once

#include "based/algorithm/max.hpp"
#include "based/algorithm/min.hpp"
#include "based/concept/is/regular.hpp"
#include "based/concept/is/same.hpp"
#include "based/concept/procedure/procedure.hpp"
#include "based/trait/remove_reference.hpp"
#include "based/utility/forward.hpp"

namespace based
{

// clamp a value between low and high
template<
    BareRegular T,
    BareRegular U,
    BareRegular V,
    RegularProcedure<bool, T, T> Rel>
  requires(BareSameAs<T, U> && BareSameAs<T, V>)
constexpr decltype(auto) clamp(T&& value, U&& low, V&& high, Rel rel)
{
  return based::max(
      based::forward<U>(low),
      based::min(based::forward<V>(high), based::forward<T>(value), rel),
      rel
  );
}

// clamp a value between low and high
template<BareRegular T, BareRegular U, BareRegular V>
  requires(BareSameAs<T, U> && BareSameAs<T, V>)
constexpr decltype(auto) clamp(T&& value, U&& low, V&& high)
{
  return based::clamp(
      based::forward<T>(value),
      based::forward<U>(low),
      based::forward<V>(high),
      [](const trait::RemoveReference<T>& llhs, const trait::RemoveReference<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
