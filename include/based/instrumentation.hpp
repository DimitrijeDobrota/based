#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace based
{

struct instrumented_base
{
  static void initialize(std::size_t size);

  static auto size() { return number_ops; }
  static auto name(std::size_t idx) { return names[idx]; }
  static auto count(std::size_t idx) { return counts[idx]; }

protected:
  enum operations : std::uint8_t
  {
    n,
    constructor_default,
    constructor_value,
    constructor_copy,
    constructor_move,
    assignment_copy,
    assignment_move,
    destructor,
    equality,
    comparison,
    _count,  // NOLINT
  };

  static constexpr const std::size_t number_ops = _count;
  static constexpr std::array<const char*, number_ops> names = {
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

  static std::array<double, number_ops> counts;
};

template<typename T>
// T is Semiregualr or Regular or TotallyOrdered
struct instrumented : instrumented_base
{
  using value_type = T;

  value_type value;

  explicit instrumented(value_type val)
      : value(std::move(val))
  {
    ++counts[constructor_value];
  }

  explicit instrumented(value_type&& val)
      : value(std::move(val))
  {
    ++counts[constructor_value];
  }

  // Semiregular:
  instrumented() { ++counts[constructor_default]; }

  instrumented(const instrumented& val)
      : value(val.value)
  {
    ++counts[constructor_copy];
  }

  instrumented(instrumented&& val) noexcept
      : value(std::move(val.value))
  {
    ++counts[constructor_move];
  }

  // self assign should be handled by the value_type
  instrumented& operator=(const instrumented& val)  // NOLINT cert-oop54-cpp
  {
    ++counts[assignment_copy];
    value = val.value;
    return *this;
  }

  // self assign should be handled by the value_type
  instrumented& operator=(instrumented&& val) noexcept  // NOLINT cert-oop54-cpp
  {
    ++counts[assignment_move];
    value = std::move(val.value);
    return *this;
  }

  ~instrumented() { ++counts[destructor]; }

  // Regular

  friend bool operator==(const instrumented& lhs, const instrumented& rhs)
  {
    ++counts[equality];
    return lhs.value == rhs.value;
  }

  friend bool operator!=(const instrumented& lhs, const instrumented& rhs)
  {
    return !(lhs == rhs);
  }

  // TotallyOrdered

  friend bool operator<(const instrumented& lhs, const instrumented& rhs)
  {
    ++counts[comparison];
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
