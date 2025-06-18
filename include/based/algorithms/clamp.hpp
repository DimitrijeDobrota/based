#pragma once

#include "based/algorithms/max.hpp"
#include "based/algorithms/min.hpp"
#include "based/concepts/is/regular.hpp"
#include "based/concepts/is/same.hpp"
#include "based/concepts/procedure/procedure.hpp"
#include "based/trait/remove/reference.hpp"
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
      [](const remove_reference_t<T>& llhs, const remove_reference_t<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
