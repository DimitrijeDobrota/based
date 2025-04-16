#pragma once

#include <cstddef>
#include <functional>
#include <type_traits>

namespace based
{

/* ----- Function Signature ----- */

template<typename>
struct signature;

template<typename Ret, typename... Args>
struct signature<Ret(Args...)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) & noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) && noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const & noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const && noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile & noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile && noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile & noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

template<typename Ret, typename Obj, bool Ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile && noexcept(Ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, Ne>;
};

/* ----- Overload Lambdas ----- */

template<typename... F>
struct overload : public F...
{
  using F::operator()...;
};

template<typename... F>
overload(F&&...) -> overload<F...>;

/* ----- Function Wrapper with type erasure ----- */

template<typename Signature, std::size_t Size = 16, std::size_t Alignment = 8>
class Function;

template<std::size_t Size,
         std::size_t Alignment,
         typename Res,
         typename... Args>
class Function<Res(Args...), Size, Alignment>
{
  alignas(Alignment) char m_space[Size] = {0};  // NOLINT *array

  using executor_t = Res (*)(Args..., void*);

  static constexpr Res default_executor(Args... /* args */, void* /* func */)
  {
    throw std::bad_function_call();
  }

  constexpr static executor_t m_default_executor = default_executor;
  executor_t m_executor = m_default_executor;

  template<typename Callable>
  static Res executor(Args... args, void* func)
  {
    return (*reinterpret_cast<Callable*>(  // NOLINT reinterpret_cast
        static_cast<Function*>(func)->m_space))(std::forward<Args>(args)...);
  }

public:
  Function() = default;

  template<typename CallableArg, typename Callable = std::decay_t<CallableArg>>
    requires(requires {
      !std::same_as<Function, Callable>;
      sizeof(Callable) <= Size;
      alignof(Callable) <= Alignment;
      std::is_trivially_destructible_v<Callable>;
      std::is_trivially_copyable_v<Callable>;
    })

  Function(CallableArg&& callable)  // NOLINT *explicit
      : m_executor(executor<Callable>)
  {
    ::new (static_cast<void*>(m_space))
        Callable(std::forward<CallableArg>(callable));
  }

  template<typename... CallArgs>
  Res operator()(CallArgs&&... callargs) const
  {
    return this->m_executor(std::forward<CallArgs>(callargs)...,
                            const_cast<Function*>(this));  // NOLINT *const_cast
  }
};

template<typename T>
Function(T) -> Function<typename signature<decltype(&T::operator())>::sig_type>;

}  // namespace based
