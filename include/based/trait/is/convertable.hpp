#pragma once

#include <type_traits>

namespace based
{

template<class From, class To>
using IsConvertible = std::is_convertible<From, To>;

template<class From, class To>
constexpr bool is_convertible_v = std::is_convertible_v<From, To>;

}  // namespace based
