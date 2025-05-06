#pragma once

#include "based/concepts/is/convertable.hpp"
#include "based/concepts/is/invocable.hpp"
#include "based/concepts/is/regular.hpp"
#include "based/concepts/procedure/domain.hpp"
#include "based/trait/integral_constant.hpp"
#include "based/trait/invoke/result.hpp"

namespace based
{

namespace detail
{

// clang-format off

template<typename P, typename Sig> struct procedure : public false_type {};

template<typename P, typename Ret, typename... Args>
requires (Invocable<P, Args...> && ConvertibleTo<invoke_result_t<P, Args...>, Ret>)
struct procedure<P, Ret(Args...)> : public true_type {};

template<typename P, typename... Args>
requires (Invocable<P, Args...>)
struct procedure<P, void(Args...)> : public true_type {};

template<typename P, typename Ret, typename... Args>
static constexpr bool procedure_v = procedure<P, Ret(Args...)>::value;

// clang-format on

}  // namespace detail

template<typename P, typename Ret, typename... Args>
concept Procedure = detail::procedure_v<P, Ret, Args...>;

template<typename P, typename Ret, typename Arg>
concept UnaryProcedure = Procedure<P, Ret, Arg>;

template<typename P, typename Ret, typename... Args>
concept RegularProcedure = requires {
  requires(Procedure<P, Ret, Args...>);
  requires(RegularDomain<Args...>);
  requires(Regular<ret_t<P, Args...>>);
};

}  // namespace based
