#pragma once

#include "based/trait/integral_constant.hpp"

namespace based::trait
{

namespace detail
{

// clang-format off

template<class>
struct IsFunctionHelper : FalseType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) volatile noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) volatile & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) volatile && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const volatile noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const volatile & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args...) const volatile && noexcept(ne)> : TrueType {};

// NOLINTBEGIN(*ambiguous-ellipsis*)

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) volatile noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) volatile & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) volatile && noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const volatile noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const volatile & noexcept(ne)> : TrueType {};

template<class Ret, bool ne, class... Args>
struct IsFunctionHelper<Ret(Args......) const volatile && noexcept(ne)> : TrueType {};

// NOLINTEND(*ambiguous-ellipsis*)

// clang-format on

}  // namespace detail

template<class T>
concept IsFunction = detail::IsFunctionHelper<T>::value;

}  // namespace based::trait
