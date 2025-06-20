#pragma once

#include "based/character/is/alpha.hpp"
#include "based/character/is/digit.hpp"
#include "based/character/type.hpp"

namespace based
{

constexpr bool is_alnum(Character chr)
{
  return is_alpha(chr) || is_digit(chr);
}

}  // namespace based
