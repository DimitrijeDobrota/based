#pragma once

#include "based/utility/move.hpp"
#include "based/utility/uncaught_exception.hpp"

namespace based
{

template<typename Func, bool on_success = false, bool on_failure = false>
class Scopeguard
{
  UncaughtExceptionDetector m_detector;
  Func m_func;

public:
  Scopeguard(Func&& func)  // NOLINT(*explicit*)
      : m_func(based::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT(*explicit*)
      : m_func(func)
  {
  }
  */

  Scopeguard(const Scopeguard&) = delete;
  Scopeguard& operator=(const Scopeguard&) = delete;

  Scopeguard(Scopeguard&&) = delete;
  Scopeguard& operator=(Scopeguard&&) = delete;

  ~Scopeguard()
  {
    if ((on_success && !m_detector) || (on_failure && m_detector)) {
      m_func();
    }
  }
};

template<typename Func>
class Scopeguard<Func, false, false>
{
  bool m_commit = false;
  Func m_func;

public:
  Scopeguard(Func&& func)  // NOLINT(*explicit*)
      : m_func(based::move(func))
  {
  }

  /*
  scopeguard(const Func& func)  // NOLINT(*explicit*)
      : m_func(func)
  {
  }
  */

  Scopeguard(const Scopeguard&) = delete;
  Scopeguard& operator=(const Scopeguard&) = delete;

  Scopeguard(Scopeguard&&) = delete;
  Scopeguard& operator=(Scopeguard&&) = delete;

  ~Scopeguard()
  {
    if (m_commit) {
      m_func();
    }
  }
  void commit() { m_commit = true; }
};

template<typename Func>
using scopeguard_exit = Scopeguard<Func, true, true>;

template<typename Func>
using scopeguard_success = Scopeguard<Func, true, false>;

template<typename Func>
using scopeguard_failure = Scopeguard<Func, false, true>;

}  // namespace based
