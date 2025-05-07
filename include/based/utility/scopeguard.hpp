#pragma once

#include "based/utility/move.hpp"
#include "based/utility/uncaught_exception.hpp"

namespace based
{

template<typename Func, bool on_success = false, bool on_failure = false>
class scopeguard
{
  uncaught_exception_detector m_detector;
  Func m_func;

public:
  scopeguard(Func&& func)  // NOLINT(*explicit*)
      : m_func(based::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT(*explicit*)
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
  scopeguard(Func&& func)  // NOLINT(*explicit*)
      : m_func(based::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT(*explicit*)
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
