#pragma once

#include "based/char/character.hpp"

namespace based
{

constexpr bool is_digit(character chr)
{
  return chr >= '0' && chr <= '9';
}

}  // namespace based

