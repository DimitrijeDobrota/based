#pragma once

#include <array>  // NOLINT
#include <cstddef>  // NOLINT

namespace based
{

#define BASED_ENUM(Name, Type, ...) \
  class Name \
  { \
  public: \
    enum Name##_ : Type {__VA_ARGS__}; \
\
  private: \
    static constexpr const std::array arr = {__VA_ARGS__}; \
\
  public: \
    static constexpr const std::size_t size = arr.size(); \
\
    using enum_type = Name##_; \
\
    explicit Name(Name::Name##_ val) \
        : m_value(val) \
    { \
    } \
\
    operator enum_type() const \
    { \
      return m_value; \
    } \
\
    Name& operator=(enum_type val) \
    { \
      m_value = val; \
      return *this; \
    } \
\
  private: \
    enum_type m_value; \
  };

}  // namespace based
