#pragma once

#include <type_traits>

namespace based::trait
{

template<class T, class... Args>
concept IsAssignable = std::is_assignable_v<T, Args...>;

template<class T, class... Args>
concept IsTriviallyAssignable = std::is_trivially_assignable_v<T, Args...>;

template<class T, class... Args>
concept IsNothrowAssignable = std::is_nothrow_assignable_v<T, Args...>;

}  // namespace based::trait
