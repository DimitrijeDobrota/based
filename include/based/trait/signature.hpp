#pragma once

#include <tuple>

#include "based/trait/conditional.hpp"
#include "based/trait/integral_constant.hpp"

namespace based
{

template<typename>
struct Signature;

template<typename Ret, bool ne, typename... Args>
struct Signature<Ret(Args...) noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, bool ne, typename... Args>
struct Signature<Ret (*)(Args...) noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = FalseType;

  using LvalrefVal = FalseType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) & noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = FalseType;

  using LvalrefVal = TrueType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) && noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = FalseType;

  using LvalrefVal = FalseType;
  using RvalrefVal = TrueType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = FalseType;

  using LvalrefVal = FalseType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const & noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = FalseType;

  using LvalrefVal = TrueType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const && noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = FalseType;

  using LvalrefVal = FalseType;
  using RvalrefVal = TrueType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) volatile noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = TrueType;

  using LvalrefVal = FalseType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) volatile & noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = TrueType;

  using LvalrefVal = TrueType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) volatile && noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = FalseType;
  using VolatileVal = TrueType;

  using LvalrefVal = FalseType;
  using RvalrefVal = TrueType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const volatile noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = TrueType;

  using LvalrefVal = FalseType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const volatile & noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = TrueType;

  using LvalrefVal = TrueType;
  using RvalrefVal = FalseType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct Signature<Ret (Obj::*)(Args...) const volatile && noexcept(ne)>
{
  using SigType = Ret(Args...);
  using ArgType = std::tuple<Args...>;
  using RetType = Ret;

  using ConstVal = TrueType;
  using VolatileVal = TrueType;

  using LvalrefVal = FalseType;
  using RvalrefVal = TrueType;

  using NoexceptVal = IntegralConstant<bool, ne>;
};

template<typename StaticCallOp>
struct SignatureStatic
{
};

template<typename Ret, bool ne, typename... Args>
struct SignatureStatic<Ret (*)(Args...) noexcept(ne)>
{
  using SigType = Ret(Args...);
};

template<typename F, typename Op>
using SignatureT = typename ConditionalT<requires(F& func) {
  (void)func.operator();
}, SignatureStatic<Op>, Signature<Op>>::SigType;

/*
template<typename Sig>
class function;

template<typename Ret, typename... Args>
class function<Ret(Args...)>
{
};

template<typename Ret, typename... Args>
function(Ret (*)(Args...)) -> function<Ret(Args...)>;

template<typename F, typename Sig = SignatureT<F, decltype(&F::operator())>>
function(F) -> function<Sig>;
*/

}  // namespace based
