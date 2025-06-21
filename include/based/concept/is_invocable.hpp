#pragma once

#include <type_traits>

namespace based::trait
{

template<class P, class... Args>
concept IsInvocable = std::is_invocable_v<P, Args...>;

template<class P, class... Args>
concept IsNothrowInvocable = std::is_nothrow_invocable_v<P, Args...>;

}  // namespace based::trait
