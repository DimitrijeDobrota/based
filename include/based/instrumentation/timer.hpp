#pragma once

#include <chrono>
#include <format>
#include <iostream>

namespace based
{

class timer
{
public:
  using clock_t = std::chrono::high_resolution_clock;
  using duration_t = std::chrono::microseconds;

  timer()
      : m_startp(clock_t::now())
  {
  }

  timer(const timer&) = delete;
  timer(timer&&) = delete;
  timer& operator=(const timer&) = delete;
  timer& operator=(timer&&) = delete;

  ~timer()
  {
    stop();
    std::cout << std::flush;
  }

  void stop()
  {
    static const auto count = [](const auto& time)
    {
      return std::chrono::time_point_cast<duration_t>(time)
          .time_since_epoch()
          .count();
    };

    const auto endp = clock_t::now();

    const auto start = count(m_startp);
    const auto end = count(endp);

    const auto duration = end - start;
    const auto msec = static_cast<double>(duration) * 0.001;

    std::cout << std::format("{}us ({}ms)\n", duration, msec);
  }

private:
  std::chrono::time_point<clock_t> m_startp;
};

}  // namespace based
