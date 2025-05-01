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
    typename Ret,
    typename... Args>
class function<Ret(Args...), size, alignment>
{
  buffer<size, alignment> m_space;

  using executor_t = Ret (*)(Args..., void*);

  static constexpr Ret default_executor(Args... /* args */, void* /* func */)
  {
    throw std::bad_function_call();
  }

  constexpr static executor_t m_default_executor = default_executor;
  executor_t m_executor = m_default_executor;

  template<typename Callable>
  static Ret executor(Args... args, void* func)
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
  Ret operator()(CallArgs&&... callargs) const
  {
    return this->m_executor(
        std::forward<CallArgs>(callargs)...,
        const_cast<function*>(this)  // NOLINT const_cast
    );
  }
};

template<typename Ret, typename... Args>
function(Ret (*)(Args...)) -> function<Ret(Args...)>;

template<typename F, typename Sig = signature_t<F, decltype(&F::operator())>>
function(F) -> function<Sig>;

template<typename Func, bool on_success = false, bool on_failure = false>
class scopeguard
{
  uncaught_exception_detector m_detector;
  Func m_func;

public:
  scopeguard(Func&& func)  // NOLINT explicit
      : m_func(std::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT explicit
      : m_func(func)
  {
  }
  */

  scopeguard(const scopeguard&) = delete;
  scopeguard& operator=(const scopeguard&) = delete;

  scopeguard(scopeguard&&) = delete;
  scopeguard& operator=(scopeguard&&) = delete;

  ~scopeguard()
  {
    if ((on_success && !m_detector) || (on_failure && m_detector)) {
      m_func();
    }
  }
};

template<typename Func>
class scopeguard<Func, false, false>
{
  bool m_commit = false;
  Func m_func;

public:
  scopeguard(Func&& func)  // NOLINT explicit
      : m_func(std::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT explicit
      : m_func(func)
  {
  }
  */

  scopeguard(const scopeguard&) = delete;
  scopeguard& operator=(const scopeguard&) = delete;

  scopeguard(scopeguard&&) = delete;
  scopeguard& operator=(scopeguard&&) = delete;

  ~scopeguard()
  {
    if (m_commit) {
      m_func();
    }
  }
  void commit() { m_commit = true; }
};

template<typename Func>
using scopeguard_exit = scopeguard<Func, true, true>;

template<typename Func>
using scopeguard_success = scopeguard<Func, true, false>;

template<typename Func>
using scopeguard_failure = scopeguard<Func, false, true>;

}  // namespace based
