#pragma once

#include "based/concepts/is/regular.hpp"
#include "based/concepts/is/same.hpp"
#include "based/concepts/procedure/procedure.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

namespace detail
{

template<typename P, typename Arg>
concept NoninputRelation = RegularProcedure<P, bool, Arg, Arg>;

}  // namespace detail

template<BareRegular T, BareRegular U, detail::NoninputRelation<T> Rel>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs, Rel rel)
{
  return rel(rhs, lhs) ? std::forward<U>(rhs) : std::forward<T>(lhs);
}

// returns min element, first if equal
template<BareRegular T, BareRegular U>
  requires BareSameAs<T, U>
decltype(auto) min(T&& lhs, U&& rhs)
{
  return based::min(
      std::forward<T>(lhs),
      std::forward<U>(rhs),
      [](const remove_reference_t<T>& llhs, const remove_reference_t<U>& lrhs)
      {
        return llhs < lrhs;
      }
  );
}

}  // namespace based
