#pragma once

#include "based/character/type.hpp"
#include "based/character/is/alpha.hpp"
#include "based/character/is/digit.hpp"

namespace based
{

constexpr bool is_alnum(character chr)
{
  return is_alpha(chr) || is_digit(chr);
}

}  // namespace based
