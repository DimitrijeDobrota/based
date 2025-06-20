#pragma once

#include "based/concept/is_convertible.hpp"
#include "based/concept/is_invocable.hpp"
#include "based/concept/is_regular.hpp"
#include "based/concept/procedure/domain.hpp"
#include "based/trait/integral_constant.hpp"
#include "based/trait/invoke_result.hpp"

namespace based
{

namespace detail
{

// clang-format off

template<typename P, typename Sig> struct Procedure : public FalseType {};

template<typename P, typename Ret, typename... Args>
requires (trait::IsInvocable<P, Args...> && trait::IsConvertible<InvokeResultT<P, Args...>, Ret>)
struct Procedure<P, Ret(Args...)> : public TrueType {};

template<typename P, typename... Args>
requires (trait::IsInvocable<P, Args...>)
struct Procedure<P, void(Args...)> : public TrueType {};

template<typename P, typename Ret, typename... Args>
static constexpr bool procedure_v = Procedure<P, Ret(Args...)>::value;

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
  requires(trait::Regular<RetT<P, Args...>>);
};

}  // namespace based
