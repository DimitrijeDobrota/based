#pragma once

#include <compare>

#include "based/integral/types.hpp"

namespace based
{

struct Character : public StrongType<char, Character>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  constexpr Character(char chr)  // NOLINT(*explicit*)
      : StrongType(chr)
  {
  }

  explicit constexpr Character(U8 ord)
      : StrongType(static_cast<char>(ord.value))
  {
  }

  [[nodiscard]] char chr() const { return value; }
  [[nodiscard]] U8 ord() const { return U8::underlying_cast(value); }

  friend constexpr bool operator==(Character lhs, char rhs)
  {
    return lhs.value == rhs;
  }

  friend constexpr bool operator==(char lhs, Character rhs)
  {
    return lhs == rhs.value;
  }

  friend constexpr auto operator<=>(Character lhs, char rhs)
  {
    return lhs.value <=> rhs;
  }

  friend constexpr auto operator<=>(char lhs, Character rhs)
  {
    return lhs <=> rhs.value;
  }
};

auto compare(Character, Character) -> bool;
auto order(Character, Character) -> bool;

}  // namespace based
