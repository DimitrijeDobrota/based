#pragma once

#include <tuple>

namespace based
{

template<typename Function, typename... CapturedArgs>
class curried
{
  template<typename FFunction, typename... FCapturedArgs>
  friend class curried;

  Function m_function;
  std::tuple<CapturedArgs...> m_captured;

  curried(Function function, std::tuple<CapturedArgs...> args)
      : m_function(function)
      , m_captured(std::move(args))
  {
  }

public:
  curried(Function function, CapturedArgs&&... args)  // NOLINT(*explicit*)
      : m_function(function)
      , m_captured(std::forward<CapturedArgs>(args)...)
  {
  }

  template<typename... NewArgs>
  auto operator()(NewArgs&&... args) const
  {
    auto all_args = std::tuple_cat(
        m_captured, std::make_tuple(std::forward<NewArgs>(args)...)
    );

    if constexpr (std::is_invocable_v<Function, CapturedArgs..., NewArgs...>) {
      return std::apply(m_function, std::move(all_args));
    } else {
      return curried<Function, CapturedArgs..., NewArgs...> {
          m_function, std::move(all_args)
      };
    }
  }
};

}  // namespace based
