#pragma once

#include <type_traits>

namespace based
{

template<class F, class... Args>
using is_invocable = std::is_invocable<F, Args...>;

template<class F, class... Args>
static constexpr bool is_invocable_v = is_invocable<F, Args...>::value;

}  // namespace based
