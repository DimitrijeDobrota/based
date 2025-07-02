#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "based/enum/enum.hpp"
#include "based/instrumentation/table.hpp"
#include "based/integral/types.hpp"
#include "based/utility/move.hpp"

namespace based
{

struct InstrumentedBase
{
  based_declare_enum(
      op,
      based::u8,
      0,
      n,
      ctor_default,
      ctor_value,
      ctor_copy,
      ctor_move,
      asgn_copy,
      asgn_move,
      destructor,
      equality,
      comparison
  );

  static op::enum_type::array<double> counts;

  static void initialize(SizeT size)
  {
    std::fill(std::begin(counts), std::end(counts), 0.0);
    std::count[op::n] = static_cast<double>(size);
  }
};

BASED_DEFINE_ENUM_CLASS(
    InstrumentedBase,
    op,
    u8,
    0,
    n,
    ctor_default,
    ctor_value,
    ctor_copy,
    ctor_move,
    asgn_copy,
    asgn_move,
    destructor,
    equality,
    comparison
)

template<typename T>
  requires std::semiregular<T>
struct instrumented : instrumented_base
{
  using value_type = T;

  value_type value;

  instrumented(const value_type& val)  // NOLINT(*explicit*)
      : value(based::move(val))
  {
    ++counts[op::ctor_value];
    ;
  }

  instrumented(value_type&& val)  // NOLINT(*explicit*)
      : value(based::move(val))
  {
    ++counts[op::ctor_value];
    ;
  }

  // trait::Semiregular:
  instrumented()
  {
    ++counts[op::ctor_default];
    ;
  }

  instrumented(const instrumented& val)
      : value(val.value)
  {
    ++counts[op::ctor_copy];
    ;
  }

  instrumented(instrumented&& val) noexcept
      : value(based::move(val.value))
  {
    ++counts[op::ctor_move];
    ;
  }

  // self assign should be handled by the value_type
  instrumented& operator=(const instrumented& val)  // NOLINT(*cert-oop54-cpp*)
  {
    ++counts[op::asgn_copy];
    ;
    value = val.value;
    return *this;
  }

  // self assign should be handled by the value_type
  instrumented& operator=(
      instrumented&& val
  ) noexcept  // NOLINT(*cert-oop54-cpp*)
  {
    ++counts[op::asgn_move];
    ;
    value = based::move(val.value);
    return *this;
  }

  ~instrumented()
  {
    ++counts[op::destructor];
    ;
  }

  // trait::Regular

  friend bool operator==(const instrumented& lhs, const instrumented& rhs)
  {
    ++counts[op::equality];
    ;
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
    ;
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

template<typename Function>
void count_operations(
    SizeT    first,
    SizeT    last,
    Function fun,
    double (*norm)(double, double) = dont_normalize
)
{
  using instrumented = instrumented<double>;
  using eSizeT = instrumented::op::enum_type::SizeType;

  constexpr eSizeT cols = instrumented::op::enum_type::size;
  const eSizeT     decimals((norm == dont_normalize) ? 0 : 2);

  InstrumentedBase::op::enum_type::array<double> values;

  static constexpr int width = 12;
  table const          tbl(width);
  tbl.print_header(
      std::begin(instrumented::op::enum_type::names),
      std::end(instrumented::op::enum_type::names)
  );

  std::mt19937 rng(0);  // NOLINT(*cert-msc32-c*, *cert-msc51-cpp*)
  while (first <= last) {
    std::vector<instrumented> vec(first);
    std::iota(std::begin(vec), std::end(vec), 0.0);
    std::shuffle(std::begin(vec), std::end(vec), rng);

    instrumented::initialize(first);
    fun(std::begin(vec), std::end(vec));

    const auto dbl = static_cast<double>(first);

    values[instrumented_base::op::n] = dbl;
    for (eSizeT k = 1; k < cols; ++k) {
      const auto& val = instrumented::op::enum_type::get(k);
      values[val] = norm(instrumented::counts[val], dbl);
    }

    tbl.print_row(std::begin(values), std::end(values), decimals);

    first <<= 1U;
  }
}

}  // namespace based
