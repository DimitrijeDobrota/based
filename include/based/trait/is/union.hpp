#pragma once

#include <type_traits>

namespace based
{

template<class T>
using IsUnion = std::is_union<T>;

template<class T>
constexpr bool is_union_v = std::is_union_v<T>;

}  // namespace based
