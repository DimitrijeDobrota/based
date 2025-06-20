#pragma once

#include <chrono>
#include <format>
#include <iostream>

namespace based
{

class Timer
{
public:
  using ClockT = std::chrono::high_resolution_clock;
  using DurationT = std::chrono::microseconds;

  Timer()
      : m_startp(ClockT::now())
  {
  }

  Timer(const Timer&) = delete;
  Timer(Timer&&) = delete;
  Timer& operator=(const Timer&) = delete;
  Timer& operator=(Timer&&) = delete;

  ~Timer()
  {
    stop();
    std::cout << std::flush;
  }

  void stop()
  {
    static const auto count = [](const auto& time)
    {
      return std::chrono::time_point_cast<DurationT>(time)
          .time_since_epoch()
          .count();
    };

    const auto endp = ClockT::now();

    const auto start = count(m_startp);
    const auto end = count(endp);

    const auto duration = end - start;
    const auto msec = static_cast<double>(duration) * 0.001;

    std::cout << std::format("{}us ({}ms)\n", duration, msec);
  }

private:
  std::chrono::time_point<ClockT> m_startp;
};

}  // namespace based
