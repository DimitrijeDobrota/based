#pragma once

#include "based/concept/is_convertible.hpp"
#include "based/utility/forward.hpp"

namespace based::trait
{

template<class T>
concept IsBoolTestable = requires(T&& val) {
  requires(IsConvertible<T, bool>);
  // clang-format off
  { !forward<T>(val) } -> IsConvertible<bool>;
  // clang-format on
};

}  // namespace based::trait
