#pragma once

#include "based/character/type.hpp"

namespace based
{

constexpr bool is_alpha_lower(Character chr)
{
  return chr >= 'a' && chr <= 'z';
}

}  // namespace based
