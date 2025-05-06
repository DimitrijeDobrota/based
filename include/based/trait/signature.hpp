#pragma once

#include <tuple>

#include "based/trait/integral_constant.hpp"

namespace based
{

template<typename>
struct signature;

template<typename Ret, bool ne, typename... Args>
struct signature<Ret(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, bool ne, typename... Args>
struct signature<Ret (*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename StaticCallOp>
struct signature_static
{
};

template<typename Ret, bool ne, typename... Args>
struct signature_static<Ret (*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
};

template<typename F, typename Op>
using signature_t = typename std::conditional_t<requires(F& func) {
  (void)func.operator();
}, signature_static<Op>, signature<Op>>::sig_type;

/*
template<typename Sig>
class function;

template<typename Ret, typename... Args>
class function<Ret(Args...)>
{
};

template<typename Ret, typename... Args>
function(Ret (*)(Args...)) -> function<Ret(Args...)>;

template<typename F, typename Sig = signature_t<F, decltype(&F::operator())>>
function(F) -> function<Sig>;
*/

}  // namespace based
