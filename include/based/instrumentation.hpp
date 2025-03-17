#pragma once

#include <algorithm>
#include <array>
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
protected:
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

public:
  static constexpr auto op_num = op::size;

  static void initialize(std::size_t size);

  static constexpr auto name(std::size_t idx) { return names[idx]; }
  static auto count(std::size_t idx) { return counts[idx]; }
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
};

template<typename Function>
void count_operations(size_t i,
                      size_t j,
                      Function fun,
                      double (*norm)(double, double) = dont_normalize)
{
  using instrumented = based::instrumented<double>;

  constexpr size_t cols = instrumented::op_num;
  const size_t normalized((norm == dont_normalize) ? 0 : 2);

  std::array<size_t, cols> decimals = {0};
  std::fill(std::next(std::begin(decimals)), std::end(decimals), normalized);

  for (size_t k = 0; k < cols; ++k) {
    std::cout << std::format("{:^12} | ", instrumented::name(k));
  }
  std::cout << '\n';

  std::mt19937 rng(0);  // NOLINT cert-msc32-c cert-msc51-cpp
  while (i <= j) {
    std::vector<instrumented> vec(i);
    std::iota(std::begin(vec), std::end(vec), 0.0);
    std::shuffle(std::begin(vec), std::end(vec), rng);

    instrumented::initialize(i);
    fun(std::begin(vec), std::end(vec));

    std::cout << std::format("{:12} | ", instrumented::count(0));
    for (size_t k = 1; k < cols; ++k) {
      std::cout << std::format(
          "{:12.{}f} | ",
          norm(instrumented::count(k), static_cast<double>(i)),
          decimals[k]);
    }
    std::cout << '\n' << std::flush;

    i <<= 1U;
  }
}

}  // namespace based
