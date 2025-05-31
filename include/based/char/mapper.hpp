#pragma once

#include <array>

#include "based/concepts/procedure/predicate.hpp"
#include "based/types/types.hpp"

namespace based
{

template<Predicate<char> Predicate>
class mapper
{
  static constexpr based::size_t size = 128;
  using mapped_type = bu8;

  static constexpr Predicate m_predicate = {};

  using direct_t = std::array<mapped_type, size>;
  static constexpr direct_t direct = []
  {
    direct_t res = {};

    mapped_type count = 0;
    for (std::size_t idx = 0; idx < size; idx++) {
      if (m_predicate(static_cast<char>(idx))) {
        res[idx] = count++;
      }
    }

    return res;
  }();

  static constexpr const std::size_t count = []
  {
    mapped_type count = 0;
    for (std::size_t idx = 0; idx < size; idx++) {
      if (m_predicate(static_cast<char>(idx))) {
        count++;
      }
    }
    return count;
  }();

  using reverse_t = std::array<char, count>;
  static constexpr reverse_t reverse = []
  {
    reverse_t res = {};

    mapped_type count = 0;
    for (std::size_t idx = 0; idx < size; idx++) {
      const auto chr = static_cast<char>(idx);
      if (m_predicate(chr)) {
        res[count++] = chr;
      }
    }

    return res;
  }();

public:
  static constexpr bool predicate(char chr) { return m_predicate(chr); }
  static constexpr char map(mapped_type value) { return reverse[value]; }
  static constexpr mapped_type map(char chr)
  {
    return direct[static_cast<based::size_t>(chr)];
  }
};

struct test
{
  constexpr bool operator()(char chr) const { return chr >= 'a' && chr <= 'z'; }
};

}  // namespace based
