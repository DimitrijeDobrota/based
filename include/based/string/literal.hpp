#pragma once

#include <array>
#include <cstddef>
#include <string_view>

namespace based
{

template<std::size_t n>
struct StringLiteral
{
  // NOLINTNEXTLINE(*explicit*, *array*)
  constexpr StringLiteral(const char (&str)[n])
      : m_value(std::to_array(str))
  {
  }

  // NOLINTNEXTLINE(*explicit*)
  [[nodiscard]] constexpr operator std::string_view() const
  {
    return {data(), size()};
  }

  [[nodiscard]] constexpr std::size_t size() const { return n - 1; }
  [[nodiscard]] constexpr const char* data() const { return m_value.data(); }

  std::array<char, n> m_value;
};

}  // namespace based
