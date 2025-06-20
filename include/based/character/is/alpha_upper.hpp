#pragma once

#include "based/character/type.hpp"

namespace based
{

constexpr bool is_alpha_upper(Character chr)
{
  return chr >= 'A' && chr <= 'Z';
}

}  // namespace based
