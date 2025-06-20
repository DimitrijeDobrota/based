#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
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

// clang-format on

}  // namespace detail

template<class T>
concept IsFunction = detail::IsFunction<T>::value;

}  // namespace based::trait
