#pragma once

#include <array>
#include <cassert>

#include "based/macros.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_LIST_ELEM_STR(Name, Index) #Name,

#define BASED_LIST_STR(...) BASED_FOREACH(BASED_LIST_ELEM_STR, __VA_ARGS__)

#define BASED_DECLARE_ENUM_VAL(Name, Index) static const type Name;

#define BASED_DECLARE_ENUM_CASE(Qualifier, Name, Index)                        \
  case Qualifier::Name.value:                                                  \
    return Name;

#define BASED_DEFINE_ENUM_VAL(Qualifier, Name, Index)                          \
  inline constexpr Qualifier::type Qualifier::Name = {                         \
      Qualifier::type::size - (Index) - 1                                      \
  };

#define BASED_DEFINE_ENUM_VALS(Qualifier, ...)                                 \
  BASED_FOREACH_1(Qualifier, BASED_DEFINE_ENUM_VAL, __VA_ARGS__)

#define BASED_DEFINE_ENUM_NAMES(Qualifier, ...)                                \
  inline constexpr Qualifier::type::array<const char*>                         \
      Qualifier::type::names = {BASED_LIST_STR(__VA_ARGS__)};

#define BASED_DEFINE_ENUM_GET(Qualifier, Type, ...)                            \
  inline const Qualifier::type& Qualifier::type::get(Type idx)                 \
  {                                                                            \
    switch (idx) {                                                             \
      BASED_FOREACH_1(Qualifier, BASED_DECLARE_ENUM_CASE, __VA_ARGS__)         \
      default:                                                                 \
        break;                                                                 \
    }                                                                          \
    assert(0); /* NOLINT(*assert*,cert-dcl03-c) */                                          \
  }

#define BASED_DEFINE_ENUM_ARRAY(Name)                                          \
  template<typename T>                                                         \
  class array : public std::array<T, Name::type::size>                         \
  {                                                                            \
    using std::array<T, Name::type::size>::operator[];                         \
                                                                               \
  public:                                                                      \
    constexpr array() = default;                                               \
                                                                               \
    /* NOLINTBEGIN(*explicit*,*decay*)*/                                       \
    template<class... Args>                                                    \
      requires(sizeof...(Args) == Name::type::size)                            \
    constexpr array(Args&&... args)                                            \
        : std::array<T, Name::type::size>({std::forward<Args>(args)...})       \
    {                                                                          \
    }                                                                          \
    /* NOLINTEND(*explicit*,*decay*)*/                                         \
                                                                               \
    const T& operator[](Name::type val) const                                  \
    {                                                                          \
      return std::array<T, Name::type::size>::operator[](val.value);           \
    }                                                                          \
                                                                               \
    T& operator[](Name::type val)                                              \
    {                                                                          \
      return std::array<T, Name::type::size>::operator[](val.value);           \
    }                                                                          \
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
    public:                                                                    \
      using size_t = Type;                                                     \
      static constexpr size_t size =                                           \
          BASED_NUMARGS(BASED_LIST_STR(__VA_ARGS__));                          \
                                                                               \
      BASED_DEFINE_ENUM_ARRAY(Name)                                            \
      static const array<const char*> names;                                   \
                                                                               \
      static const type& get(Type idx);                                        \
                                                                               \
      Type value;                                                              \
    };                                                                         \
                                                                               \
    BASED_FOREACH(BASED_DECLARE_ENUM_VAL, __VA_ARGS__)                         \
  };

#define BASED_DEFINE_ENUM(Name, Type, ...)                                     \
  BASED_DEFINE_ENUM_VALS(Name, __VA_ARGS__)                                    \
  BASED_DEFINE_ENUM_NAMES(Name, __VA_ARGS__)                                   \
  BASED_DEFINE_ENUM_GET(Name, __VA_ARGS__)

#define BASED_DEFINE_CLASS_ENUM(Class, Name, Type, ...)                        \
  BASED_DEFINE_ENUM_VALS(Class::Name, __VA_ARGS__)                             \
  BASED_DEFINE_ENUM_NAMES(Class::Name, __VA_ARGS__)                            \
  BASED_DEFINE_ENUM_GET(Class::Name, Type, __VA_ARGS__)

// NOLINTEND(*macro-usage*)
