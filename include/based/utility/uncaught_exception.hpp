#pragma once

#include <exception>

namespace based
{

class UncaughtExceptionDetector
{
  int m_count;

public:
  UncaughtExceptionDetector()
      : m_count(std::uncaught_exceptions())
  {
  }

  operator bool() const noexcept  // NOLINT(*explicit*)
  {
    return std::uncaught_exceptions() > m_count;
  }
};

}  // namespace based
