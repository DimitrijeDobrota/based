#pragma once

#include <array>
#include <cstddef>

namespace based
{

template<std::size_t n>
struct string_literal
{
  // NOLINTNEXTLINE(*explicit*, *array*)
  constexpr string_literal(const char (&str)[n])
      : m_value(std::to_array(str))
  {
  }

  [[nodiscard]] constexpr std::size_t size() const { return n; }
  [[nodiscard]] constexpr const char* data() const { return m_value.data(); }

  std::array<char, n> m_value;
};

}  // namespace based
