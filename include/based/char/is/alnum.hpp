#pragma once

#include "based/char/is/alpha.hpp"
#include "based/char/is/digit.hpp"

namespace based
{

constexpr bool is_alnum(char chr)
{
  return is_alpha(chr) || is_digit(chr);
}

}  // namespace based
