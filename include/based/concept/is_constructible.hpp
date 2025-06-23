#pragma once

#include <type_traits>

namespace based::trait
{

template<class T, class... Args>
concept IsConstructible = std::is_constructible_v<T, Args...>;

template<class T, class... Args>
concept IsTriviallyConstructible =
    std::is_trivially_constructible_v<T, Args...>;

template<class T, class... Args>
concept IsNothrowConstructible = std::is_nothrow_constructible_v<T, Args...>;

}  // namespace based::trait
