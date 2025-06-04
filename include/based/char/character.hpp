#pragma once

#include "based/types/types.hpp"

namespace based
{

struct character : public strong_type<char, character>
{
  using strong_type::strong_type;
  using strong_type::operator=;

  constexpr character(char chr)  // NOLINT(*explicit*)
      : strong_type(chr)
  {
  }

  explicit constexpr character(u8 ord)
      : strong_type(static_cast<char>(ord.value))
  {
  }

  [[nodiscard]] char chr() const { return value; }
  [[nodiscard]] u8 ord() const { return u8::underlying_cast(value); }

  friend constexpr bool operator==(character lhs, char rhs)
  {
    return lhs.value == rhs;
  }

  friend constexpr bool operator==(char lhs, character rhs)
  {
    return lhs == rhs.value;
  }

  friend constexpr auto operator<=>(character lhs, char rhs)
  {
    return lhs.value <=> rhs;
  }

  friend constexpr auto operator<=>(char lhs, character rhs)
  {
    return lhs <=> rhs.value;
  }
};

auto compare(character, character) -> bool;
auto order(character, character) -> bool;

}  // namespace based
