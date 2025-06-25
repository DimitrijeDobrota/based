#pragma once

#include <type_traits>

namespace based::trait
{

template<class T>
concept IsDestructible = std::is_destructible_v<T>;

template<class T>
concept IsTriviallyDestructible = std::is_trivially_destructible_v<T>;

template<class T>
concept IsNothrowDestructible = std::is_nothrow_destructible_v<T>;

}  // namespace based::trait
