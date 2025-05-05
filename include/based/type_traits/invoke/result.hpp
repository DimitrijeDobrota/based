#pragma once

#include <type_traits>

namespace based
{

template<class F, class... Args>
using invoke_result = std::invoke_result<F, Args...>;

template<class F, class... Args>
using invoke_result_t = invoke_result<F, Args...>::type;

}  // namespace based
