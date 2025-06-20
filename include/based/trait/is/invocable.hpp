#pragma once

#include <type_traits>

namespace based
{

template<class F, class... Args>
using IsInvocable = std::is_invocable<F, Args...>;

template<class F, class... Args>
constexpr bool is_invocable_v = std::is_invocable_v<F, Args...>;

template<class F, class... Args>
using IsNothrowInvocable = std::is_nothrow_invocable<F, Args...>;

template<class F, class... Args>
constexpr bool is_nothrow_invocable_v = std::is_nothrow_invocable_v<F, Args...>;

}  // namespace based
