#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

// clang-format off

template<typename>
struct is_function : false_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) volatile && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args...) const volatile && noexcept(ne)> : true_type {};

// NOLINTBEGIN(*ambiguous-ellipsis*)

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) volatile && noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const volatile noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const volatile & noexcept(ne)> : true_type {};

template<typename Ret, bool ne, typename... Args>
struct is_function<Ret(Args......) const volatile && noexcept(ne)> : true_type {};

// NOLINTEND(*ambiguous-ellipsis*)

template<class T> constexpr bool is_function_v = is_function<T>::value;

// clang-format on

}  // namespace based
