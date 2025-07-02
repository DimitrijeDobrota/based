#pragma once

#include <compare>

#include "based/integral/types.hpp"
#include "based/integral/strong.hpp"

namespace based
{

struct Character : public StrongType<U8, Character>
{
  using StrongType::StrongType;
  using StrongType::operator=;

  constexpr Character(char chr)  // NOLINT(*explicit*)
      : StrongType(underlying_cast(static_cast<unsigned char>(chr)))
  {
  }

  explicit constexpr Character(U8 ord)
      : StrongType(ord)
  {
  }

  [[nodiscard]] char chr() const { return static_cast<char>(value.value); }
  [[nodiscard]] U8   ord() const { return U8::underlying_cast(value); }

  friend constexpr bool operator==(Character lhs, Character rhs)
  {
    return lhs.value == rhs.value;
  }

  friend constexpr bool operator==(Character lhs, char rhs)
  {
    return lhs.value.value == static_cast<unsigned char>(rhs);
  }

  friend constexpr bool operator==(char lhs, Character rhs)
  {
    return static_cast<unsigned char>(lhs) == rhs.value.value;
  }

  friend constexpr auto operator<=>(Character lhs, Character rhs)
  {
    return lhs.value <=> rhs.value;
  }

  friend constexpr auto operator<=>(Character lhs, char rhs)
  {
    return lhs.value.value <=> rhs;
  }

  friend constexpr auto operator<=>(char lhs, Character rhs)
  {
    return lhs <=> rhs.value.value;
  }
};

}  // namespace based
