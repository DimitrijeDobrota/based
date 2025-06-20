#pragma once

#include <functional>

#include "based/concept/is_same.hpp"
#include "based/integral/types.hpp"
#include "based/trait/decay.hpp"
#include "based/trait/signature.hpp"
#include "based/utility/buffer.hpp"
#include "based/utility/forward.hpp"

namespace based
{

/* ----- Function Wrapper with type erasure ----- */

template<
    typename Signature,
    SizeT size = sizeof(void*),
    SizeT alignment = alignof(void*)>
class Function;

template<SizeT size, SizeT alignment, typename Ret, typename... Args>
class Function<Ret(Args...), size, alignment>
{
  Buffer<size, alignment> m_space {};

  using ExecutorT = Ret (*)(Args..., void*);

  static constexpr Ret default_executor(Args... /* args */, void* /* func */)
  {
    throw std::bad_function_call();
  }

  constexpr static ExecutorT m_default_executor = default_executor;
  ExecutorT m_executor = m_default_executor;

  template<typename Callable>
  static Ret executor(Args... args, void* func)
  {
    return std::invoke(
        *static_cast<Function*>(func)->m_space.template as<Callable>(),
        based::forward<Args>(args)...
    );
  }

public:
  Function() = default;

  template<typename CallableArg, typename Callable = trait::Decay<CallableArg>>
    requires(requires {
              !trait::IsSame<Function, Callable>;
              sizeof(Callable) <= size;
              alignof(Callable) <= alignment;
              std::is_trivially_destructible_v<Callable>;
              std::is_trivially_copyable_v<Callable>;
            })

  Function(CallableArg&& callable)  // NOLINT(*explicit*)
      : m_space(
            std::in_place_type<Callable>, based::forward<CallableArg>(callable)
        )
      , m_executor(executor<Callable>)
  {
  }

  template<typename... CallArgs>
  Ret operator()(CallArgs&&... callargs) const
  {
    return this->m_executor(
        based::forward<CallArgs>(callargs)...,
        const_cast<Function*>(this)  // NOLINT(*const-cast*)
    );
  }
};

template<typename Ret, typename... Args>
Function(Ret (*)(Args...)) -> Function<Ret(Args...)>;

template<typename F, typename Sig = SignatureT<F, decltype(&F::operator())>>
Function(F) -> Function<Sig>;

}  // namespace based
