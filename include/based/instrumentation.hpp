#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <concepts>
#include <cstddef>
#include <cstdint>

#include "based/enum.hpp"

namespace based
{

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

}  // namespace based
