#pragma once

#include <array>
#include <cstddef>

namespace based
{

template<size_t n>
struct string_literal
{
  // NOLINTNEXTLINE(*explicit*, *array*)
  constexpr string_literal(const char (&str)[n])
      : m_value(std::to_array(str))
  {
  }

  [[nodiscard]] constexpr size_t size() const { return n; }
  [[nodiscard]] constexpr const char* data() const { return m_value.data(); }

  std::array<char, n> m_value;
};

}  // namespace based
