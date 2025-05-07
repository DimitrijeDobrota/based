#pragma once

#include <functional>

#include "based/concepts/is/same.hpp"
#include "based/trait/signature.hpp"
#include "based/types/types.hpp"
#include "based/utility/buffer.hpp"
#include "based/utility/forward.hpp"

namespace based
{

/* ----- Function Wrapper with type erasure ----- */

template<
    typename Signature,
    size_t size = sizeof(void*),
    size_t alignment = alignof(void*)>
class function;

template<size_t size, size_t alignment, typename Ret, typename... Args>
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
        based::forward<Args>(args)...
    );
  }

public:
  function() = default;

  template<typename CallableArg, typename Callable = std::decay_t<CallableArg>>
    requires(requires {
              !SameAs<function, Callable>;
              sizeof(Callable) <= size;
              alignof(Callable) <= alignment;
              std::is_trivially_destructible_v<Callable>;
              std::is_trivially_copyable_v<Callable>;
            })

  function(CallableArg&& callable)  // NOLINT(*explicit*)
      : m_space(std::in_place_type<Callable>, based::forward<CallableArg>(callable))
      , m_executor(executor<Callable>)
  {
  }

  template<typename... CallArgs>
  Ret operator()(CallArgs&&... callargs) const
  {
    return this->m_executor(
        based::forward<CallArgs>(callargs)...,
        const_cast<function*>(this)  // NOLINT(*const-cast*)
    );
  }
};

template<typename Ret, typename... Args>
function(Ret (*)(Args...)) -> function<Ret(Args...)>;

template<typename F, typename Sig = signature_t<F, decltype(&F::operator())>>
function(F) -> function<Sig>;

}  // namespace based
