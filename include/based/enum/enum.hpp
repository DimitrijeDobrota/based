#pragma once

#include "based/assert.hpp"
#include "based/container/array.hpp"
#include "based/macro/foreach.hpp"
#include "based/macro/foreach_1.hpp"
#include "based/macro/foreach_2.hpp"
#include "based/types/types.hpp"
#include "based/utility/forward.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_E_DETAIL_NUMARGS(...) based::u(std::array {__VA_ARGS__}.size())

#define BASED_E_DETAIL_LIST_ELEM_STR(Name, Index) #Name,

#define BASED_E_DETAIL_LIST_STR(...)                                           \
  BASED_FOREACH(BASED_E_DETAIL_LIST_ELEM_STR, __VA_ARGS__)

#define BASED_E_DETAIL_SET(Var, Value)                                         \
  /* NOLINTNEXTLINE(*macro-parentheses*) */                                    \
  decltype(Var) Var = decltype(Var) {Value};

#define BASED_E_DETAIL_DECLARE_VAL(Name, Var, Index) static const Name Var;

#define BASED_E_DETAIL_DECLARE_CASE(Qualifier, Var, Index)                     \
  case Qualifier::Var():                                                       \
    return Var;

#define BASED_E_DETAIL_DEFINE_VAL(Qualifier, Initial, Var, Index)              \
  inline constexpr BASED_E_DETAIL_SET(                                         \
      Qualifier::Var,                                                          \
      Qualifier::value_type {Initial} + Qualifier::size                        \
          - Qualifier::value_type {Index} - Qualifier::value_type {1_u}        \
  )

#define BASED_E_DETAIL_DEFINE_NAMES(Qualifier, ...)                            \
  inline constexpr BASED_E_DETAIL_SET(                                         \
      Qualifier::names, BASED_E_DETAIL_LIST_STR(__VA_ARGS__)                   \
  )

#define BASED_E_DETAIL_DEFINE_GET(Qualifier, Type, ...)                        \
  inline const Qualifier& Qualifier::get(Type idx)                             \
  {                                                                            \
    /* NOLINTNEXTLINE(*paths-covered*) */                                      \
    switch (static_cast<Type::basic_type>(idx)) {                              \
      BASED_FOREACH_1(Qualifier, BASED_E_DETAIL_DECLARE_CASE, __VA_ARGS__)     \
      default:                                                                 \
        break;                                                                 \
    }                                                                          \
    assert(0); /* NOLINT(*assert*,cert-dcl03-c) */                             \
  }

#define BASED_E_DETAIL_DEFINE(Qualifier, Type, Initial, ...)                   \
  BASED_FOREACH_2(Qualifier, Initial, BASED_E_DETAIL_DEFINE_VAL, __VA_ARGS__)  \
  BASED_E_DETAIL_DEFINE_NAMES(Qualifier, __VA_ARGS__)                          \
  BASED_E_DETAIL_DEFINE_GET(Qualifier, Type, __VA_ARGS__)

#define BASED_DECLARE_ARRAY(Name, Initial)                                     \
  template<typename T>                                                         \
  class array : public based::array<T, Name::size_type, Name::size>            \
  {                                                                            \
    using enum_type = Name;                                                    \
    using base = based::array<T, Name::size_type, enum_type::size>;            \
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
      requires(enum_type::size_type(sizeof...(Args)) == enum_type::size)       \
    constexpr explicit array(Args&&... args                                    \
    ) noexcept /* NOLINTNEXTLINE(*decay*) */                                   \
        : base({based::forward<Args>(args)...})                                \
    {                                                                          \
    }                                                                          \
                                                                               \
    const T& operator[](enum_type val) const                                   \
    {                                                                          \
      return base::operator[](val.value - enum_type::value_type {Initial});    \
    }                                                                          \
                                                                               \
    T& operator[](enum_type val)                                               \
    {                                                                          \
      return base::operator[](val.value - enum_type::value_type {Initial});    \
    }                                                                          \
                                                                               \
    const T& at(enum_type val) const                                           \
    {                                                                          \
      return base::operator[](val.value - enum_type::value_type {Initial});    \
    }                                                                          \
                                                                               \
    T& at(enum_type val)                                                       \
    {                                                                          \
      return base::operator[](val.value - enum_type::value_type {Initial});    \
    }                                                                          \
  };

#define BASED_DECLARE_ENUM(Name, Type, Initial, ...)                           \
  struct Name                                                                  \
  {                                                                            \
    constexpr explicit Name(Type enum_value)                                   \
        : value(enum_value)                                                    \
    {                                                                          \
    }                                                                          \
                                                                               \
  public:                                                                      \
    using value_type = Type;                                                   \
    using size_type = Type;                                                    \
                                                                               \
    static constexpr size_type size =                                          \
        BASED_E_DETAIL_NUMARGS(BASED_E_DETAIL_LIST_STR(__VA_ARGS__));          \
                                                                               \
    BASED_DECLARE_ARRAY(Name, Initial)                                         \
    static const array<const char*> names;                                     \
                                                                               \
    static const Name& get(Type idx);                                          \
                                                                               \
    constexpr auto operator()() const                                          \
    {                                                                          \
      return static_cast<Type::basic_type>(value);                             \
    }                                                                          \
                                                                               \
    friend bool operator==(Name lhs, Name rhs)                                 \
    {                                                                          \
      return lhs.value == rhs.value;                                           \
    }                                                                          \
                                                                               \
    Type value;                                                                \
                                                                               \
    BASED_FOREACH_1(Name, BASED_E_DETAIL_DECLARE_VAL, __VA_ARGS__)             \
  };

#define BASED_DEFINE_ENUM(Name, Type, Initial, ...)                            \
  BASED_E_DETAIL_DEFINE(Name, Type, Initial, __VA_ARGS__)

#define BASED_DEFINE_ENUM_CLASS(Class, Name, Type, Initial, ...)               \
  BASED_E_DETAIL_DEFINE(Class::Name, Type, Initial, __VA_ARGS__)

// NOLINTEND(*macro-usage*)
