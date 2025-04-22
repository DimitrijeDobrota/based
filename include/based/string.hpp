#pragma once

#include <array>
#include <cstddef>

namespace based
{

template<std::size_t N>
struct string_literal
{
  // NOLINTNEXTLINE *-explicit-constructor *-avoid-c-arrays
  constexpr string_literal(const char (&str)[N])
      : m_value(std::to_array(str))
  {
  }

  constexpr std::size_t size() const { return N; }
  constexpr const char* data() const { return m_value.data(); }

  std::array<char, N> m_value;
};

}  // namespace based
