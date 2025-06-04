#pragma once

#include "based/char/character.hpp"

namespace based
{

constexpr bool is_xdigit(character chr)
{
  return (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F')
      || (chr >= '0' && chr <= '9');
}

}  // namespace based
