#pragma once

#include <array>
#include <cassert>

#include "based/macros.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_LIST_ELEM_STR(Name, Index) #Name,

#define BASED_LIST_STR(...) BASED_FOREACH(BASED_LIST_ELEM_STR, __VA_ARGS__)

// NOLINTNEXTLINE(*macro-parentheses*)
#define BASED_SET(var, val) decltype(var) var = decltype(var) {val};

#define BASED_DETAIL_ENUM_DECLARE_VAL(Name, Index) static const type Name;

#define BASED_DETAIL_ENUM_DECLARE_CASE(Qualifier, Name, Index)                 \
  case Qualifier::Name.value:                                                  \
    return Name;

#define BASED_DETAIL_ENUM_DEFINE_VAL(Qualifier, Name, Index)                   \
  inline constexpr BASED_SET(                                                  \
      Qualifier::Name, Qualifier::type::size - (Index) - 1                     \
  )

#define BASED_DETAIL_ENUM_DEFINE_VALS(Qualifier, ...)                          \
  BASED_FOREACH_1(Qualifier, BASED_DETAIL_ENUM_DEFINE_VAL, __VA_ARGS__)

#define BASED_DETAIL_ENUM_DEFINE_NAMES(Qualifier, ...)                         \
  inline constexpr BASED_SET(                                                  \
      Qualifier::type::names, BASED_LIST_STR(__VA_ARGS__)                      \
  )

#define BASED_DETAIL_ENUM_DEFINE_GET(Qualifier, Type, ...)                     \
  inline const Qualifier::type& Qualifier::type::get(Type idx)                 \
  {                                                                            \
    /* NOLINTNEXTLINE(*paths-covered*) */                                      \
    switch (idx) {                                                             \
      BASED_FOREACH_1(Qualifier, BASED_DETAIL_ENUM_DECLARE_CASE, __VA_ARGS__)  \
      default:                                                                 \
        break;                                                                 \
    }                                                                          \
    assert(0); /* NOLINT(*assert*,cert-dcl03-c) */                             \
  }

#define BASED_DETAIL_ENUM_DEFINE(Qualifier, Type, ...)                         \
  BASED_DETAIL_ENUM_DEFINE_VALS(Qualifier, __VA_ARGS__)                        \
  BASED_DETAIL_ENUM_DEFINE_NAMES(Qualifier, __VA_ARGS__)                       \
  BASED_DETAIL_ENUM_DEFINE_GET(Qualifier, Type, __VA_ARGS__)

#define BASED_ENUM_DECLARE_ARRAY(Name)                                         \
  template<typename T>                                                         \
  class array : public std::array<T, Name::type::size>                         \
  {                                                                            \
    using base = std::array<T, Name::type::size>;                              \
    using base::operator[];                                                    \
                                                                               \
  public:                                                                      \
    constexpr array() noexcept                                                 \
        : base()                                                               \
    {                                                                          \
    }                                                                          \
                                                                               \
    template<class... Args>                                                    \
      requires(sizeof...(Args) == Name::type::size)                            \
    constexpr explicit array(Args&&... args                                    \
    ) noexcept /* NOLINTNEXTLINE(*decay*) */                                   \
        : base({std::forward<Args>(args)...})                                  \
    {                                                                          \
    }                                                                          \
                                                                               \
    const T& operator[](Name::type val) const                                  \
    {                                                                          \
      return base::operator[](val.value);                                      \
    }                                                                          \
                                                                               \
    T& operator[](Name::type val)                                              \
    {                                                                          \
      return base::operator[](val.value);                                      \
    }                                                                          \
  };

#define BASED_ENUM_DECLARE(Name, Type, ...)                                    \
  struct Name                                                                  \
  {                                                                            \
    class type                                                                 \
    {                                                                          \
      friend Name;                                                             \
                                                                               \
      constexpr explicit type(Type enum_value)                                 \
          : value(enum_value)                                                  \
      {                                                                        \
      }                                                                        \
                                                                               \
    public:                                                                    \
      using size_t = Type;                                                     \
      static constexpr size_t size =                                           \
          BASED_NUMARGS(BASED_LIST_STR(__VA_ARGS__));                          \
                                                                               \
      BASED_ENUM_DECLARE_ARRAY(Name)                                           \
      static const array<const char*> names;                                   \
                                                                               \
      static const type& get(Type idx);                                        \
                                                                               \
      friend bool operator==(type lhs, type rhs)                               \
      {                                                                        \
        return lhs.value == rhs.value;                                         \
      }                                                                        \
                                                                               \
      Type value;                                                              \
    };                                                                         \
                                                                               \
    BASED_FOREACH(BASED_DETAIL_ENUM_DECLARE_VAL, __VA_ARGS__)                  \
  };

#define BASED_ENUM_DEFINE(Name, Type, ...)                                     \
  BASED_DETAIL_ENUM_DEFINE(Name, Type, __VA_ARGS__)

#define BASED_DEFINE_CLASS_ENUM(Class, Name, Type, ...)                        \
  BASED_DETAIL_ENUM_DEFINE(Class::Name, Type, __VA_ARGS__)

// NOLINTEND(*macro-usage*)
