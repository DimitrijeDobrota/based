#pragma once

#include <cassert>

#include "based/type_traits.hpp"

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

/* ----- Relation modifiers ----- */

template<typename T, Relation<T> Rel>
auto complement(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return !rel(lhs, rhs);
  };
}

template<typename T, Relation<T> Rel>
auto converse(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return rel(rhs, lhs);
  };
}

template<typename T, Relation<T> Rel>
auto complement_of_converse(Rel rel)
{
  return [=](const T& lhs, const T& rhs)
  {
    return !rel(rhs, lhs);
  };
}

template<typename T, Relation<T> Rel>
auto lower_bound_predicate(const T& goal, Rel rel)
{
  return [=](const T& val)
  {
    return !rel(val, goal);
  };
}

template<typename T, Relation<T> Rel>
auto upper_bound_predicate(const T& goal, Rel rel)
{
  return [=](const T& val)
  {
    return rel(goal, val);
  };
}

}  // namespace based
