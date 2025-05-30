#pragma once

#include "based/char/is/alpha_lower.hpp"
#include "based/char/is/alpha_upper.hpp"

namespace based
{

constexpr bool is_alpha(char chr)
{
  return is_alpha_lower(chr) || is_alpha_upper(chr);
}

}  // namespace based
