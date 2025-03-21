#pragma once

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <format>
#include <iostream>
#include <numbers>
#include <numeric>
#include <random>
#include <vector>

#include "based/enum.hpp"

namespace based
{

class table
{
public:
  explicit table(std::size_t min_wth)
      : m_min_wth(min_wth)
  {
  }

  template<typename I>
  void print_header(I first, I last)
  {
    while (first != last) {
      std::cout << std::format("{:^{}} | ", *first, m_min_wth);
      first++;
    }
    std::cout << '\n';
  }

  template<typename I>
  void print_row(I first, I last, std::size_t precision)
  {
    std::cout << std::format("{:{}} | ", *first++, m_min_wth);
    while (first != last) {
      std::cout << std::format("{:{}.{}f} | ", *first, m_min_wth, precision);
      first++;
    }
    std::cout << '\n';
  }

private:
  std::size_t m_min_wth;
};

inline auto dont_normalize(double x, double /* n */)
{
  return x;
}

inline auto normalize_n(double x, double n)
{
  return x / n;
}

inline auto normalize_nlogn(double x, double n)
{
  return x / (n * (std::log(n) / std::numbers::ln2));
}

inline auto normalize_nlogn1(double x, double n)
{
  return x / (n * std::log(n) - n);
}

struct instrumented_base
{
  BASED_ENUM(op,
             std::uint8_t,
             n,
             ctor_default,
             ctor_value,
             ctor_copy,
             ctor_move,
             asgn_copy,
             asgn_move,
             destructor,
             equality,
             comparison)

  static constexpr std::array<const char*, op::size> names = {
      "n",
      "ctor_default",
      "ctor_value",
      "ctor_copy",
      "ctor_move",
      "asgn_copy",
      "asgn_move",
      "destructor",
      "equality",
      "comparison",
  };

  static std::array<double, op::size> counts;

  static constexpr auto op_num = op::size;

  static void initialize(std::size_t size);
};

template<typename T>
  requires std::semiregular<T>
struct instrumented : instrumented_base
{
  using value_type = T;

  value_type value;

  instrumented(const value_type& val)  // NOLINT *-explicit-constructor
      : value(std::move(val))
  {
    ++counts[op::ctor_value];
  }

  instrumented(value_type&& val)  // NOLINT *-explicit-constructor
      : value(std::move(val))
  {
    ++counts[op::ctor_value];
  }

  // Semiregular:
  instrumented() { ++counts[op::ctor_default]; }

  instrumented(const instrumented& val)
      : value(val.value)
  {
    ++counts[op::ctor_copy];
  }

  instrumented(instrumented&& val) noexcept
      : value(std::move(val.value))
  {
    ++counts[op::ctor_move];
  }

  // self assign should be handled by the value_type
  instrumented& operator=(const instrumented& val)  // NOLINT cert-oop54-cpp
  {
    ++counts[op::asgn_copy];
    value = val.value;
    return *this;
  }

  // self assign should be handled by the value_type
  instrumented& operator=(instrumented&& val) noexcept  // NOLINT cert-oop54-cpp
  {
    ++counts[op::asgn_move];
    value = std::move(val.value);
    return *this;
  }

  ~instrumented() { ++counts[op::destructor]; }

  // Regular

  friend bool operator==(const instrumented& lhs, const instrumented& rhs)
  {
    ++counts[op::equality];
    return lhs.value == rhs.value;
  }

  friend bool operator!=(const instrumented& lhs, const instrumented& rhs)
  {
    return !(lhs == rhs);
  }

  // TotallyOrdered

  friend bool operator<(const instrumented& lhs, const instrumented& rhs)
  {
    ++counts[op::comparison];
    return lhs.value < rhs.value;
  }

  friend bool operator>(const instrumented& lhs, const instrumented& rhs)
  {
    return rhs < lhs;
  }

  friend bool operator<=(const instrumented& lhs, const instrumented& rhs)
  {
    return !(rhs < lhs);
  }

  friend bool operator>=(const instrumented& lhs, const instrumented& rhs)
  {
    return !(lhs < rhs);
  }

  friend std::ostream& operator<<(std::ostream& ost, const instrumented& rhs)
  {
    return ost << rhs.value;
  }
};

template<typename Function>
void count_operations(size_t i,
                      size_t j,
                      Function fun,
                      double (*norm)(double, double) = dont_normalize)
{
  using instrumented = based::instrumented<double>;

  constexpr size_t cols = instrumented::op_num;
  const size_t decimals((norm == dont_normalize) ? 0 : 2);

  std::array<double, cols> values = {0};

  table tbl(12);
  tbl.print_header(std::begin(instrumented::names),
                   std::end(instrumented::names));

  std::mt19937 rng(0);  // NOLINT cert-msc32-c cert-msc51-cpp
  while (i <= j) {
    std::vector<instrumented> vec(i);
    std::iota(std::begin(vec), std::end(vec), 0.0);
    std::shuffle(std::begin(vec), std::end(vec), rng);

    instrumented::initialize(i);
    fun(std::begin(vec), std::end(vec));

    const auto dbl = static_cast<double>(i);

    values[0] = dbl;
    for (size_t k = 1; k < cols; ++k) {
      values[k] = norm(instrumented::counts[k], dbl);
    }

    tbl.print_row(std::begin(values), std::end(values), decimals);

    i <<= 1U;
  }
}

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
    const auto ms = static_cast<double>(duration) * 0.001;

    std::cout << std::format("{}us ({}ms)\n", duration, ms);
  }

private:
  std::chrono::time_point<clock_t> m_startp;
};

}  // namespace based
