#pragma once

#include <tuple>

#include "based/utility/forward.hpp"
#include "based/utility/move.hpp"

namespace based
{

template<typename Function, typename... CapturedArgs>
class Curried
{
  template<typename FFunction, typename... FCapturedArgs>
  friend class Curried;

  Function                    m_function;
  std::tuple<CapturedArgs...> m_captured;

  Curried(Function function, std::tuple<CapturedArgs...> args)
      : m_function(function)
      , m_captured(based::move(args))
  {
  }

public:
  Curried(Function function, CapturedArgs&&... args)  // NOLINT(*explicit*)
      : m_function(function)
      , m_captured(based::forward<CapturedArgs>(args)...)
  {
  }

  template<typename... NewArgs>
  auto operator()(NewArgs&&... args) const
  {
    auto all_args = std::tuple_cat(
        m_captured, std::make_tuple(based::forward<NewArgs>(args)...)
    );

    if constexpr (std::is_invocable_v<Function, CapturedArgs..., NewArgs...>) {
      return std::apply(m_function, based::move(all_args));
    } else {
      return Curried<Function, CapturedArgs..., NewArgs...> {
          m_function, based::move(all_args)
      };
    }
  }
};

}  // namespace based
