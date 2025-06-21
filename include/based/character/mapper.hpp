#pragma once

#include "based/character/type.hpp"
#include "based/concept/procedure/predicate.hpp"
#include "based/container/array.hpp"
#include "based/integral/literals.hpp"

namespace based
{

template<trait::IsPredicate<Character> Predicate>
class Mapper
{
  static constexpr auto size = limits<U8>::max;
  using MappedType = U8;

  static constexpr Predicate m_predicate = {};

  using DirectT = Array<MappedType, U8, size>;
  static constexpr DirectT direct = []
  {
    DirectT res = {};

    MappedType count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(Character::cast(idx))) {
        res[idx] = count++;
      }
    }

    return res;
  }();

  static constexpr const U8 count = []
  {
    MappedType count = 0_u8;
    for (auto idx = 0_u8; idx < size; idx++) {
      if (m_predicate(Character::cast(idx))) {
        count++;
      }
    }
    return count;
  }();

  using ReverseT = Array<Character, U8, count>;
  static constexpr ReverseT reverse = []
  {
    ReverseT res = {};

    MappedType count = 0_u8;
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
  static constexpr Character map(MappedType value) { return reverse[value]; }
  static constexpr MappedType map(Character chr) { return direct[chr.ord()]; }
};

}  // namespace based
