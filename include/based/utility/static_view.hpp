#pragma once

#include <algorithm>
#include <array>
#include <span>
#include <string>

#include "based/trait/decay.hpp"
#include "based/utility/make_static.hpp"

namespace based
{

template<class T>
struct OversizedArray
{
  static constexpr auto oversized_size = static_cast<std::size_t>(10 * 1024);

  using value_type = T;

  std::array<T, oversized_size> data {};
  std::size_t                   size {};

  constexpr auto begin() { return std::begin(data); }
  constexpr auto end()
  {
    return std::next(std::begin(data), static_cast<std::ptrdiff_t>(size));
  }

  [[nodiscard]] constexpr auto begin() const { return std::begin(data); }
  [[nodiscard]] constexpr auto end() const
  {
    return std::next(std::begin(data), static_cast<std::ptrdiff_t>(size));
  }
};

template<class Data>
consteval auto to_oversized_array(const Data& str)
{
  OversizedArray<typename Data::value_type> result;
  std::ranges::copy(str, std::begin(result));
  result.size = str.size();
  return result;
}

constexpr auto to_right_sized_array(auto callable)
{
  constexpr auto oversized = to_oversized_array(callable());

  using value_type = typename trait::Decay<decltype(oversized)>::value_type;
  std::array<value_type, oversized.size> result {};
  std::ranges::copy(oversized, std::begin(result));
  return result;
}

consteval auto to_string_view(auto callable)
{
  constexpr auto& static_data = make_static<to_right_sized_array(callable)>;

  using value_type = typename trait::Decay<decltype(static_data)>::value_type;
  const std::basic_string_view<value_type> result = {
      std::begin(static_data), std::end(static_data)
  };
  return result;
}

consteval auto to_span(auto callable)
{
  constexpr auto& static_data = make_static<to_right_sized_array(callable)>;

  using value_type = typename trait::Decay<decltype(static_data)>::value_type;
  std::span<const value_type> result(static_data.begin(), static_data.end());
  return result;
}

}  // namespace based
