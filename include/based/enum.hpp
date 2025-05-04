#pragma once

#include <array>

#include "based/macros.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_DECLARE_ENUM_VAL(Name, Index) static const type Name;

#define BASED_DEFINE_ENUM_VAL(Macro, Name, Index)                              \
  inline constexpr Macro::type Macro::Name = {Macro::type::size - (Index) - 1};

#define BASED_DEFINE_ENUM_CLASS_VAL(Class, Macro, Name, Index)                 \
  inline constexpr Class::Macro::type Class::Macro::Name = {                   \
      Class::Macro::type::size - (Index) - 1                                   \
  };

#define BASED_DECLARE_ENUM(Name, Type, ...)                                    \
  struct Name                                                                  \
  {                                                                            \
    class type                                                                 \
    {                                                                          \
      friend Name;                                                             \
                                                                               \
      /* NOLINTNEXTLINE(*explicit*) */                                         \
      constexpr type(Type enum_value)                                          \
          : value(enum_value)                                                  \
      {                                                                        \
      }                                                                        \
                                                                               \
      static constexpr std::array m_names = {                                  \
          BASED_FOREACH(BASED_INIT_LIST_STRING, __VA_ARGS__)                   \
      };                                                                       \
                                                                               \
    public:                                                                    \
      static constexpr auto size = m_names.size();                             \
      static constexpr auto names = m_names;                                   \
                                                                               \
      static auto name(type value)                                             \
      {                                                                        \
        return m_names[value.value];                                           \
      }                                                                        \
                                                                               \
      Type value;                                                              \
    };                                                                         \
                                                                               \
    BASED_FOREACH(BASED_DECLARE_ENUM_VAL, __VA_ARGS__)                         \
  };

#define BASED_DEFINE_ENUM(Class, Name, Type, ...)                              \
  BASED_FOREACH_1(Name, BASED_DEFINE_ENUM_VAL, __VA_ARGS__)

#define BASED_DEFINE_CLASS_ENUM(Class, Name, Type, ...)                        \
  BASED_FOREACH_2(Class, Name, BASED_DEFINE_ENUM_CLASS_VAL, __VA_ARGS__)

// NOLINTEND(*macro-usage*)
