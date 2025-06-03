#pragma once

#include "based/types/types.hpp"

namespace based
{

class character : public strong_type<unsigned char, character>
{
  static constexpr auto cast(char pos)
  {
    return static_cast<unsigned char>(pos);
  }

  static constexpr auto cast(unsigned char pos)
  {
    return static_cast<char>(pos);
  }

public:
  using strong_type::strong_type;
  using strong_type::operator=;

  explicit constexpr character(char chr)
      : strong_type(cast(chr))
  {
  }

  explicit constexpr character(u8 ord)
      : strong_type(ord.value)
  {
  }

  [[nodiscard]] char chr() const { return cast(value); }
  [[nodiscard]] u8 ord() const { return u8::basic_cast(value); }

  friend constexpr bool operator==(character lhs, char rhs)
  {
    return lhs.value == cast(rhs);
  }

  friend constexpr bool operator==(char lhs, character rhs)
  {
    return cast(lhs) == rhs.value;
  }

  friend constexpr auto operator<=>(character lhs, char rhs)
  {
    return lhs.value <=> cast(rhs);
  }

  friend constexpr auto operator<=>(char lhs, character rhs)
  {
    return cast(lhs) <=> rhs.value;
  }
};

auto compare(character, character) -> bool;
auto order(character, character) -> bool;

}  // namespace based
