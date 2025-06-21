#pragma once

#include "based/concept/is_convertible.hpp"
#include "based/concept/is_invocable.hpp"
#include "based/concept/is_regular.hpp"
#include "based/concept/procedure/domain.hpp"
#include "based/trait/integral_constant.hpp"
#include "based/trait/invoke_result.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off

template<class P, class Sig> struct IsProcedureHelper : public FalseType {};

template<class P, class Ret, class... Args>
requires (IsInvocable<P, Args...> && IsConvertible<InvokeResult<P, Args...>, Ret>)
struct IsProcedureHelper<P, Ret(Args...)> : public TrueType {};

template<class P, class... Args>
requires (IsInvocable<P, Args...>)
struct IsProcedureHelper<P, void(Args...)> : public TrueType {};

// clang-format on

}  // namespace detail

template<class P, class Ret, class... Args>
concept IsProcedure = detail::IsProcedureHelper<P, Ret(Args...)>::value;

template<class P, class Ret, class Arg>
concept IsProcedureUnary = IsProcedure<P, Ret, Arg>;

template<class P, class Ret, class... Args>
concept IsProcedureRegular = requires {
  requires(IsProcedure<P, Ret, Args...>);
  requires(IsDomainRegular<Args...>);
  requires(IsRegular<RetT<P, Args...>>);
};

}  // namespace based::trait
