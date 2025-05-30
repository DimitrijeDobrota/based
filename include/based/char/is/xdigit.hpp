#pragma once

namespace based
{

constexpr bool is_xdigit(char chr)
{
  return (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F')
      || (chr >= '0' && chr <= '9');
}

}  // namespace based
