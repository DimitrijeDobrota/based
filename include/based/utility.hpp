#pragma once

#include <exception>

namespace based
{

class uncaught_exception_detector
{
  int m_count;

public:
  uncaught_exception_detector()
      : m_count(std::uncaught_exceptions())
  {
  }

  operator bool() const noexcept  // NOLINT explicit
  {
    return std::uncaught_exceptions() > m_count;
  }
};

}  // namespace based
