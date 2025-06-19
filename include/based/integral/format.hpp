#pragma once

#include <format>
#include <ostream>

#include "based/integral/types.hpp"

template<>
struct std::formatter<based::i8>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::i8 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::i16>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::i16 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::i32>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::i32 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::i64>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::i64 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::u8>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::u8 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::u16>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::u16 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::u32>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::u32 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

template<>
struct std::formatter<based::u64>
{
  static constexpr auto parse(std::format_parse_context& ctx)
  {
    return ctx.begin();
  }

  static auto format(based::u64 value, std::format_context& ctx)
  {
    return std::format_to(ctx.out(), "{}", value.value);
  }
};

inline std::ostream& operator<<(std::ostream& ost, based::i8 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::i16 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::i32 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::i64 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::u8 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::u16 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::u32 value)
{
  return ost << value.value;
}

inline std::ostream& operator<<(std::ostream& ost, based::u64 value)
{
  return ost << value.value;
}
