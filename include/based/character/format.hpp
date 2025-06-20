#pragma once

#include <format>
#include <ostream>

#include "based/character/type.hpp"

template<>
struct std::formatter<based::character>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::character value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.chr());
  }
};

inline std::ostream& operator<<(std::ostream& ost, based::Character value)
{
  return ost << value.chr();
}
