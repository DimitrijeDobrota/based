#pragma once

#include <type_traits>

namespace based::trait
{

template<typename P, typename... Args>
concept IsInvocable = std::is_invocable_v<P, Args...>;

template<typename P, typename... Args>
concept IsNothrowInvocable = std::is_nothrow_invocable_v<P, Args...>;

}  // namespace based::trait
