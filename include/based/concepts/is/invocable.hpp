#pragma once

#include <concepts>

namespace based
{

template<typename P, typename... Args>
concept Invocable = std::invocable<P, Args...>;

}  // namespace based
