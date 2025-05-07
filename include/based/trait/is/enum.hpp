#pragma once

#include <type_traits>

namespace based
{

template<class T>
using is_enum = std::is_enum<T>;

template<class T>
constexpr bool is_enum_v = std::is_enum_v<T>;

}  // namespace based
