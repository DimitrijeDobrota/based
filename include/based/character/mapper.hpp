#pragma once

#include "based/character/type.hpp"
#include "based/concept/procedure/predicate.hpp"
#include "based/container/array.hpp"
#include "based/integral/literals.hpp"

namespace based
{

template<Predicate<Character> Predicate>
class Mapper
{
  static constexpr auto size = limits<U8>::max;
  using mapped_type = U8;

  static constexpr Predicate m_predicate = {};

  using direct_t = Array<mapped_type, U8, size>;
  static constexpr direct_t direct = []
  {
    direct_t res = {};

    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(Character::cast(idx))) {
        res[idx] = count++;
      }
    }

    return res;
  }();

  static constexpr const U8 count = []
  {
    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(Character::cast(idx))) {
        count++;
      }
    }
    return count;
  }();

  using reverse_t = Array<Character, U8, count>;
  static constexpr reverse_t reverse = []
  {
    reverse_t res = {};

    mapped_type count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      const auto chr = Character::cast(idx);
      if (m_predicate(chr)) {
        res[count++] = chr;
      }
    }

    return res;
  }();

public:
  static constexpr bool predicate(Character chr) { return m_predicate(chr); }
  static constexpr Character map(mapped_type value) { return reverse[value]; }
  static constexpr mapped_type map(Character chr) { return direct[chr.ord()]; }
};

}  // namespace based
