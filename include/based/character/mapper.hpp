#pragma once

#include "based/character/type.hpp"
#include "based/concept/procedure/predicate.hpp"
#include "based/container/array.hpp"
#include "based/integral/literals.hpp"

namespace based
{

template<Predicate<character> Predicate>
class mapper
{
  static constexpr auto size = limits<u8>::max;
  using mapped_type = u8;

  static constexpr Predicate m_predicate = {};

  using direct_t = array<mapped_type, u8, size>;
  static constexpr direct_t direct = []
  {
    direct_t res = {};

    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(character::cast(idx))) {
        res[idx] = count++;
      }
    }

    return res;
  }();

  static constexpr const u8 count = []
  {
    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(character::cast(idx))) {
        count++;
      }
    }
    return count;
  }();

  using reverse_t = array<character, u8, count>;
  static constexpr reverse_t reverse = []
  {
    reverse_t res = {};

    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      const auto chr = character::cast(idx);
      if (m_predicate(chr)) {
        res[count++] = chr;
      }
    }

    return res;
  }();

public:
  static constexpr bool predicate(character chr) { return m_predicate(chr); }
  static constexpr character map(mapped_type value) { return reverse[value]; }
  static constexpr mapped_type map(character chr) { return direct[chr.ord()]; }
};

}  // namespace based
