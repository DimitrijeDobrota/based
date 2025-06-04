#pragma once

#include "based/char/character.hpp"
#include "based/char/is/alpha.hpp"
#include "based/char/is/digit.hpp"

namespace based
{

constexpr bool is_alnum(character chr)
{
  return is_alpha(chr) || is_digit(chr);
}

}  // namespace based
