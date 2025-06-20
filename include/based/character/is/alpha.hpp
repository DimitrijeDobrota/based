#pragma once

#include "based/character/is/alpha_lower.hpp"
#include "based/character/is/alpha_upper.hpp"
#include "based/character/type.hpp"

namespace based
{

constexpr bool is_alpha(Character chr)
{
  return is_alpha_lower(chr) || is_alpha_upper(chr);
}

}  // namespace based
