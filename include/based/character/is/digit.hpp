#pragma once

#include "based/character/type.hpp"

namespace based
{

constexpr bool is_digit(Character chr)
{
  return chr >= '0' && chr <= '9';
}

}  // namespace based
