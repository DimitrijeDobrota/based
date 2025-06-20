#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

// clang-format off

template<typename>
struct IsFunction : false_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) volatile && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args...) const volatile && noexcept(ne)> : true_type {};

// NOLINTBEGIN(*ambiguous-ellipsis*)

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) volatile && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct IsFunction<Ret(Args......) const volatile && noexcept(ne)> : true_type {};

// NOLINTEND(*ambiguous-ellipsis*)

template<class T> constexpr bool is_function_v = IsFunction<T>::value;

// clang-format on

}  // namespace based
