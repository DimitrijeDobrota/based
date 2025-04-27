#pragma once

#include <concepts>
#include <cstddef>
#include <cstring>
#include <functional>
#include <type_traits>
#include <utility>

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

/* ----- Buffer used for Local Buffer Optimization ----- */

template<size_t S, size_t A = alignof(void*)>
struct Buffer
{
  static constexpr auto size = S;
  static constexpr auto alignment = A;

  template<typename T>
  static constexpr bool valid_type()
  {
    return sizeof(T) <= S && (A % sizeof(T)) == 0;
  }

  alignas(alignment) char m_space[size] = {0};  // NOLINT array

  Buffer() = default;

  template<typename T, typename... Args>
    requires(valid_type<T>() && std::constructible_from<T, Args...>)
  explicit Buffer(
      std::in_place_type_t<T> /* t */, Args&&... args
  ) noexcept(std::is_nothrow_constructible_v<T, Args...>)
  {
    static_assert(std::is_trivially_destructible_v<T>);
    static_assert(std::is_trivially_copyable_v<T>);
    ::new (static_cast<void*>(as<T>())) T(std::forward<Args>(args)...);
  }

  template<typename T, typename... Args>
    requires(valid_type<T>() && std::constructible_from<T, Args...>)
  T* emplace(Args&&... args
  ) noexcept(std::is_nothrow_constructible_v<T, Args...>)
  {
    static_assert(std::is_trivially_destructible_v<T>);
    static_assert(std::is_trivially_copyable_v<T>);

    // NOLINTNEXTLINE owning-memory
    return ::new (static_cast<void*>(as<T>())) T(std::forward<Args>(args)...);
  }

  template<typename T>
    requires(valid_type<T>())
  T* as() noexcept
  {
    return reinterpret_cast<T*>(&m_space);  // NOLINT reinterpret_cast
  }

  template<typename T>
    requires(valid_type<T>())
  const T* as() const noexcept
  {
    return const_cast<Buffer*>(this)->as<T>();  // NOLINT const_cast
  }

  void swap(Buffer& that) noexcept
  {
    alignas(alignment) char tmp[size];  // NOLINT array
    ::memcpy(tmp, this->m_space, size);
    ::memcpy(this->m_space, that.m_space, size);
    ::memcpy(that.m_space, tmp, size);
  }
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

template<
    std::size_t Size,
    std::size_t Alignment,
    typename Res,
    typename... Args>
class Function<Res(Args...), Size, Alignment>
{
  Buffer<Size, Alignment> m_space;

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
    return std::invoke(
        *static_cast<Function*>(func)->m_space.template as<Callable>(),
        std::forward<Args>(args)...
    );
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
      : m_space(
            std::in_place_type<Callable>, std::forward<CallableArg>(callable)
        )
      , m_executor(executor<Callable>)
  {
  }

  template<typename... CallArgs>
  Res operator()(CallArgs&&... callargs) const
  {
    return this->m_executor(
        std::forward<CallArgs>(callargs)...,
        const_cast<Function*>(this)  // NOLINT *const_cast
    );
  }
};

template<typename T>
Function(T) -> Function<typename signature<decltype(&T::operator())>::sig_type>;

}  // namespace based
