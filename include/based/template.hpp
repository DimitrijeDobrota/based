#pragma once

#include <concepts>
#include <cstddef>
#include <cstring>
#include <functional>
#include <type_traits>
#include <utility>

#include "based/type_traits.hpp"
#include "based/utility.hpp"

namespace based
{

/* ----- Function Signature ----- */

template<typename>
struct signature;

template<typename Ret, bool ne, typename... Args>
struct signature<Ret(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::false_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::false_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::true_type;
  using rvalref_val = std::false_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = std::true_type;
  using volatile_val = std::true_type;

  using lvalref_val = std::false_type;
  using rvalref_val = std::true_type;

  using noexcept_val = std::integral_constant<bool, ne>;
};

/* ----- Buffer used for Local Buffer Optimization ----- */

template<size_t size, size_t alignment = alignof(void*)>
struct buffer
{
  template<typename T>
  static constexpr bool valid_type()
  {
    return sizeof(T) <= size && (alignment % sizeof(T)) == 0;
  }

  alignas(alignment) char m_space[size] = {0};  // NOLINT array

  buffer() = default;

  template<typename T, typename... Args>
    requires(valid_type<T>() && std::constructible_from<T, Args...>)
  explicit buffer(
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
  [[nodiscard]] T* as() noexcept
  {
    return reinterpret_cast<T*>(&m_space);  // NOLINT reinterpret_cast
  }

  template<typename T>
    requires(valid_type<T>())
  [[nodiscard]] const T* as() const noexcept
  {
    return const_cast<buffer*>(this)->as<T>();  // NOLINT const_cast
  }

  void swap(buffer& that) noexcept
  {
    alignas(alignment) char tmp[size];  // NOLINT array
    ::memcpy(tmp, this->m_space, size);  // NOLINT array
    ::memcpy(this->m_space, that.m_space, size);  // NOLINT array
    ::memcpy(that.m_space, tmp, size);  // NOLINT array
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

template<
    typename Signature,
    std::size_t size = sizeof(void*),
    std::size_t alignment = alignof(void*)>
class function;

template<
    std::size_t size,
    std::size_t alignment,
    typename Res,
    typename... Args>
class function<Res(Args...), size, alignment>
{
  buffer<size, alignment> m_space;

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
        *static_cast<function*>(func)->m_space.template as<Callable>(),
        std::forward<Args>(args)...
    );
  }

public:
  function() = default;

  template<typename CallableArg, typename Callable = std::decay_t<CallableArg>>
    requires(requires {
              !std::same_as<function, Callable>;
              sizeof(Callable) <= size;
              alignof(Callable) <= alignment;
              std::is_trivially_destructible_v<Callable>;
              std::is_trivially_copyable_v<Callable>;
            })

  function(CallableArg&& callable)  // NOLINT explicit
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
        const_cast<function*>(this)  // NOLINT const_cast
    );
  }
};

// operator()
template<typename T>
function(T) -> function<typename signature<decltype(&T::operator())>::sig_type>;

// free function
template<typename T>
function(T) -> function<typename signature<std::remove_pointer_t<T>>::sig_type>;

/*
// member procedure
template<typename T>
function(T) -> function<typename signature<std::decay_t<T>>::sig_type>;
*/

template<Procedure Func, bool on_success = false, bool on_failure = false>
class scopeguard
{
  uncaught_exception_detector m_detector;
  Func m_func;

public:
  explicit scopeguard(Func&& func)
      : m_func(std::move(func))
  {
  }

  explicit scopeguard(const Func& func)
      : m_func(func)
  {
  }

  scopeguard(const scopeguard&) = delete;
  scopeguard& operator=(const scopeguard&) = delete;

  scopeguard(scopeguard&&) = default;
  scopeguard& operator=(scopeguard&&) = default;

  ~scopeguard()
  {
    if ((on_success && !m_detector) || (on_failure && m_detector)) {
      m_func();
    }
  }
};

template<Procedure Func>
class scopeguard<Func, false, false>
{
  bool m_commit = false;
  Func m_func;

public:
  explicit scopeguard(Func&& func)
      : m_func(std::move(func))
  {
  }

  explicit scopeguard(const Func& func)
      : m_func(func)
  {
  }

  scopeguard(const scopeguard&) = delete;
  scopeguard& operator=(const scopeguard&) = delete;

  scopeguard(scopeguard&&) = default;
  scopeguard& operator=(scopeguard&&) = default;

  ~scopeguard()
  {
    if (m_commit) {
      m_func();
    }
  }
  void commit() { m_commit = true; }
};

template<Procedure Func>
using scopeguard_exit = scopeguard<Func, true, true>;

template<Procedure Func>
using scopeguard_success = scopeguard<Func, true, false>;

template<Procedure Func>
using scopeguard_failure = scopeguard<Func, false, true>;

}  // namespace based
