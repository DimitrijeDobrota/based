#pragma once

#include <cassert>

#include "based/macro/foreach.hpp"
#include "based/macro/foreach_1.hpp"

// NOLINTBEGIN(*macro-usage*)

#define BASED_EF_DETAIL_NUMARGS(...) (std::array {__VA_ARGS__}.size())

#define BASED_EF_DETAIL_LIST_ELEM_STR(Name, Index) #Name,

#define BASED_EF_DETAIL_LIST_STR(...)                                          \
  BASED_FOREACH(BASED_EF_DETAIL_LIST_ELEM_STR, __VA_ARGS__)

// NOLINTNEXTLINE(*macro-parentheses*)
#define BASED_EF_DETAIL_SET(var, val) decltype(var) var = decltype(var) {val};

#define BASED_EF_DETAIL_DECLARE_ENUM_VAL(Name, Index) static const type Name;

#define BASED_EF_DETAIL_DECLARE_ENUM_CASE(Qualifier, Name, Index)              \
  case Qualifier::Name.value:                                                  \
    return Name;

#define BASED_EF_DETAIL_DEFINE_VAL(Qualifier, Name, Index)                     \
  inline constexpr BASED_EF_DETAIL_SET(                                        \
      Qualifier::Name,                                                         \
      Qualifier::type::value_type {1}                                          \
          << Qualifier::type::value_type {Qualifier::type::size - (Index) - 2} \
  )

#define BASED_EF_DETAIL_DEFINE_VALS(Qualifier, First, ...)                     \
  BASED_FOREACH_1(Qualifier, BASED_EF_DETAIL_DEFINE_VAL, __VA_ARGS__)          \
  inline constexpr BASED_EF_DETAIL_SET(Qualifier::First, 0)

#define BASED_EF_DETAIL_DEFINE_GET(Qualifier, Type, ...)                       \
  inline const Qualifier::type& Qualifier::type::get(Type idx)                 \
  {                                                                            \
    /* NOLINTNEXTLINE(*paths-covered*) */                                      \
    switch (idx) {                                                             \
      BASED_FOREACH_1(                                                         \
          Qualifier, BASED_EF_DETAIL_DECLARE_ENUM_CASE, __VA_ARGS__            \
      )                                                                        \
      default:                                                                 \
        break;                                                                 \
    }                                                                          \
    assert(0); /* NOLINT(*assert*,cert-dcl03-c) */                             \
  }

#define BASED_EF_DETAIL_DEFINE(Qualifier, Type, ...)                           \
  BASED_EF_DETAIL_DEFINE_VALS(Qualifier, __VA_ARGS__)                          \
  BASED_EF_DETAIL_DEFINE_GET(Qualifier, Type, __VA_ARGS__)

#define BASED_DECLARE_ENUM_FLAG(Name, Type, ...)                               \
  struct Name                                                                  \
  {                                                                            \
    class type                                                                 \
    {                                                                          \
      friend Name;                                                             \
      friend struct based::enum_flag_wrapper<type>;                            \
                                                                               \
      constexpr explicit type(Type enum_value)                                 \
          : value(enum_value)                                                  \
      {                                                                        \
      }                                                                        \
                                                                               \
    public:                                                                    \
      using value_type = Type;                                                 \
      using size_type = Type;                                                  \
                                                                               \
      static constexpr size_type size =                                        \
          BASED_EF_DETAIL_NUMARGS(BASED_EF_DETAIL_LIST_STR(__VA_ARGS__));      \
                                                                               \
      static const type& get(Type idx);                                        \
                                                                               \
      type& set(type val)                                                      \
      {                                                                        \
        return *this |= val;                                                   \
      }                                                                        \
                                                                               \
      type& mask(type val)                                                     \
      {                                                                        \
        return *this &= val;                                                   \
      }                                                                        \
                                                                               \
      type& tgl(type val)                                                      \
      {                                                                        \
        return *this ^= val;                                                   \
      }                                                                        \
                                                                               \
      type& neg()                                                              \
      {                                                                        \
        return *this = ~*this;                                                 \
      }                                                                        \
                                                                               \
      type& clear(type val)                                                    \
      {                                                                        \
        return *this &= ~val;                                                  \
      }                                                                        \
                                                                               \
      bool test(type val) const                                                \
      {                                                                        \
        return (*this & val) == val;                                           \
      }                                                                        \
                                                                               \
      friend bool operator==(type lhs, type rhs)                               \
      {                                                                        \
        return lhs.value == rhs.value;                                         \
      }                                                                        \
                                                                               \
      friend type operator|(type lhs, type rhs)                                \
      {                                                                        \
        return type(lhs.value | rhs.value);                                    \
      }                                                                        \
                                                                               \
      friend type operator&(type lhs, type rhs)                                \
      {                                                                        \
        return type(lhs.value & rhs.value);                                    \
      }                                                                        \
                                                                               \
      friend type operator^(type lhs, type rhs)                                \
      {                                                                        \
        return type(lhs.value ^ rhs.value);                                    \
      }                                                                        \
                                                                               \
      type operator~() const                                                   \
      {                                                                        \
        return type(~value);                                                   \
      }                                                                        \
                                                                               \
      type& operator|=(type rhs)                                               \
      {                                                                        \
        value |= rhs.value;                                                    \
        return *this;                                                          \
      }                                                                        \
                                                                               \
      type& operator&=(type rhs)                                               \
      {                                                                        \
        value &= rhs.value;                                                    \
        return *this;                                                          \
      }                                                                        \
                                                                               \
      type& operator^=(type rhs)                                               \
      {                                                                        \
        value ^= rhs.value;                                                    \
        return *this;                                                          \
      }                                                                        \
                                                                               \
      Type value;                                                              \
    };                                                                         \
                                                                               \
    BASED_FOREACH(BASED_EF_DETAIL_DECLARE_ENUM_VAL, __VA_ARGS__)               \
  };

#define BASED_DEFINE_ENUM_FLAG(Name, Type, ...)                                \
  BASED_EF_DETAIL_DEFINE(Name, Type, __VA_ARGS__)

#define BASED_DEFINE_ENUM_FLAG_CLASS(Class, Name, Type, ...)                   \
  BASED_EF_DETAIL_DEFINE(Class::Name, Type, __VA_ARGS__)

namespace based
{

template<class FlagType>
struct enum_flag_wrapper : public FlagType
{
  using value_type = FlagType::value_type;

  explicit enum_flag_wrapper(value_type& value)
      : FlagType(value)
      , m_value(&value)
  {
  }

  enum_flag_wrapper& operator=(FlagType flag)
  {
    *m_value = flag.value;
    return *this;
  }

  ~enum_flag_wrapper() { *m_value = FlagType::value; }

  enum_flag_wrapper(const enum_flag_wrapper&) = delete;
  enum_flag_wrapper& operator=(const enum_flag_wrapper&) = delete;

  enum_flag_wrapper(enum_flag_wrapper&&) = default;
  enum_flag_wrapper& operator=(enum_flag_wrapper&&) = default;

private:
  value_type* m_value;
};

}  // namespace based

// NOLINTEND(*macro-usage*)
