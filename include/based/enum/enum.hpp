#pragma once

#include <array>
#include <cassert>

#include "based/macro/foreach.hpp"
#include "based/macro/foreach_1.hpp"
#include "based/utility/forward.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_DETAIL_NUMARGS(...) (std::array {__VA_ARGS__}.size())

#define BASED_DETAIL_LIST_ELEM_STR(Name, Index) #Name,

#define BASED_DETAIL_LIST_STR(...)                                             \
  BASED_FOREACH(BASED_DETAIL_LIST_ELEM_STR, __VA_ARGS__)

// NOLINTNEXTLINE(*macro-parentheses*)
#define BASED_DETAIL_SET(var, val) decltype(var) var = decltype(var) {val};

#define BASED_DETAIL_DECLARE_ENUM_VAL(Name, Index) static const type Name;

#define BASED_DETAIL_DECLARE_ENUM_CASE(Qualifier, Name, Index)                 \
  case Qualifier::Name.value:                                                  \
    return Name;

#define BASED_DETAIL_DEFINE_ENUM_VAL(Qualifier, Name, Index)                   \
  inline constexpr BASED_DETAIL_SET(                                           \
      Qualifier::Name, Qualifier::type::size - (Index) - 1                     \
  )

#define BASED_DETAIL_DEFINE_ENUM_NAMES(Qualifier, ...)                         \
  inline constexpr BASED_DETAIL_SET(                                           \
      Qualifier::type::names, BASED_DETAIL_LIST_STR(__VA_ARGS__)               \
  )

#define BASED_DETAIL_DEFINE_ENUM_GET(Qualifier, Type, ...)                     \
  inline const Qualifier::type& Qualifier::type::get(Type idx)                 \
  {                                                                            \
    /* NOLINTNEXTLINE(*paths-covered*) */                                      \
    switch (idx) {                                                             \
      BASED_FOREACH_1(Qualifier, BASED_DETAIL_DECLARE_ENUM_CASE, __VA_ARGS__)  \
      default:                                                                 \
        break;                                                                 \
    }                                                                          \
    assert(0); /* NOLINT(*assert*,cert-dcl03-c) */                             \
  }

#define BASED_DETAIL_DEFINE_ENUM(Qualifier, Type, ...)                         \
  BASED_FOREACH_1(Qualifier, BASED_DETAIL_DEFINE_ENUM_VAL, __VA_ARGS__)        \
  BASED_DETAIL_DEFINE_ENUM_NAMES(Qualifier, __VA_ARGS__)                       \
  BASED_DETAIL_DEFINE_ENUM_GET(Qualifier, Type, __VA_ARGS__)

#define BASED_DECLARE_ENUM_ARRAY(Name)                                         \
  template<typename T>                                                         \
  class array : public std::array<T, Name::type::size>                         \
  {                                                                            \
    using base = std::array<T, Name::type::size>;                              \
    using base::operator[];                                                    \
    using base::at;                                                            \
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
        : base({based::forward<Args>(args)...})                                \
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
                                                                               \
    const T& at(Name::type val) const                                          \
    {                                                                          \
      return base::operator[](val.value);                                      \
    }                                                                          \
                                                                               \
    T& at(Name::type val)                                                      \
    {                                                                          \
      return base::operator[](val.value);                                      \
    }                                                                          \
  };

#define BASED_DECLARE_ENUM(Name, Type, ...)                                    \
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
          BASED_DETAIL_NUMARGS(BASED_DETAIL_LIST_STR(__VA_ARGS__));            \
                                                                               \
      BASED_DECLARE_ENUM_ARRAY(Name)                                           \
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
    BASED_FOREACH(BASED_DETAIL_DECLARE_ENUM_VAL, __VA_ARGS__)                  \
  };

#define BASED_DEFINE_ENUM(Name, Type, ...)                                     \
  BASED_DETAIL_DEFINE_ENUM(Name, Type, __VA_ARGS__)

#define BASED_DEFINE_ENUM_CLASS(Class, Name, Type, ...)                        \
  BASED_DETAIL_DEFINE_ENUM(Class::Name, Type, __VA_ARGS__)

// NOLINTEND(*macro-usage*)
