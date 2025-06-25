#pragma once

#include <type_traits>

namespace based::trait
{

template<class T>
concept IsSwappable = std::is_swappable_v<T>;

template<class T, class U>
concept IsSwappableWith = std::is_swappable_with_v<T, U>;

template<class T>
concept IsNothrowSwappable = std::is_nothrow_swappable_v<T>;

template<class T, class U>
concept IsNothrowSwappableWith = std::is_nothrow_swappable_with_v<T, U>;

}  // namespace based::trait
