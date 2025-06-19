#pragma once

#include "based/trait/is/invocable.hpp"

namespace based
{

template<typename P, typename... Args>
concept Invocable = is_invocable_v<P, Args...>;

}  // namespace based
