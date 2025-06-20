#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

// clang-format off

template<typename>
struct IsFunction : FalseType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile && noexcept(ne)> : TrueType {};

// NOLINTBEGIN(*ambiguous-ellipsis*)

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile && noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile & noexcept(ne)> : TrueType {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile && noexcept(ne)> : TrueType {};

// NOLINTEND(*ambiguous-ellipsis*)

template<class T> constexpr bool is_function_v = IsFunction<T>::value;

// clang-format on

}  // namespace based
