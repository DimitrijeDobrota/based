#pragma once

#include <type_traits>

namespace based::trait
{

template<class From, class To>
concept IsConvertible = std::is_convertible_v<From, To>;

}  // namespace based::trait
