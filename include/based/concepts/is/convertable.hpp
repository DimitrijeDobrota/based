#pragma once

#include "based/type_traits/is/convertable.hpp"
#include "based/utility/declvar.hpp"

namespace based
{

template<class From, class To>
concept ConvertibleTo = requires {
  requires(is_convertible_v<From, To>);
  static_cast<To>(declval<From>());
};

}  // namespace based
