#pragma once

// NOLINTBEGIN(*macro-usage*,*macro-parentheses*,*naming*)

namespace based
{

template<typename V>
class builder_type
{
protected:
  V m_val;  // NOLINT (*protected*)

public:
  template<class FV1>
  using rebind = builder_type<V>;

  using value_type = builder_type;
  using basic_type = V;

  constexpr ~builder_type() = default;

  constexpr explicit builder_type()
      : m_val(V())
  {
  }

  constexpr explicit builder_type(V value)
      : m_val(value)
  {
  }

  constexpr builder_type(const builder_type&) = default;
  constexpr builder_type& operator=(const builder_type&) = default;

  constexpr builder_type(builder_type&&) = default;
  constexpr builder_type& operator=(builder_type&&) = default;

  [[nodiscard]] auto value() const { return m_val; }
};

#define BASED_B_DETAIL_COMMON(Name)                                            \
  template<class FV1>                                                          \
  using rebind = Name<V, FV1>;                                                 \
                                                                               \
  using base_type::base_type;                                                  \
  using base_type::operator=;                                                  \
                                                                               \
  using value_type = typename base_type::value_type;                           \
  using basic_type = typename value_type::basic_type;                          \
                                                                               \
  /* NOLINTNEXTLINE(*crtp*) */                                                 \
  constexpr explicit Name(value_type value)                                    \
      : base_type(value)                                                       \
  {                                                                            \
  }

#define BASED_B_DETAIL_TEMPLATE(Name)                                          \
  template<class V, class FV = void>                                           \
  class Name : public V::template rebind<FV>                                   \
  {                                                                            \
    using base_type = typename V::template rebind<FV>;                         \
                                                                               \
  public:                                                                      \
    BASED_B_DETAIL_COMMON(Name) X(FV, Name)                                    \
  };

#define BASED_B_DETAIL_SPECIALIZATION(Name)                                    \
  template<class V>                                                            \
  class Name<V, void> : public V::template rebind<Name<V>>                     \
  {                                                                            \
    using base_type = typename V::template rebind<Name<V>>;                    \
                                                                               \
  public:                                                                      \
    BASED_B_DETAIL_COMMON(Name) X(Name, Name)                                  \
  };

#define BASED_BUILDER_DECORATOR(Name)                                          \
  BASED_B_DETAIL_TEMPLATE(Name) BASED_B_DETAIL_SPECIALIZATION(Name)

#define X(FV, Name)                                                            \
  /* NOLINTNEXTLINE(*explicit*) */                                             \
  Name(basic_type rhs)                                                         \
      : base_type(rhs)                                                         \
  {                                                                            \
  }                                                                            \
                                                                               \
  Name& operator=(V rhs)                                                       \
  {                                                                            \
    this->m_val = rhs;                                                         \
    return *this;                                                              \
  }

BASED_BUILDER_DECORATOR(ImplicitFrom)
#undef X

#define X(FV, Name)                                                            \
  operator basic_type()                                                        \
  {                                                                            \
    return this->m_val;                                                        \
  }                                                                            \
                                                                               \
  operator const basic_type() const                                            \
  {                                                                            \
    return this->m_val;                                                        \
  }
BASED_BUILDER_DECORATOR(ImplicitTo)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr bool operator==(FV lhs, FV rhs)                             \
  {                                                                            \
    return lhs.m_val == rhs.m_val;                                             \
  }
BASED_BUILDER_DECORATOR(Comparable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto operator<=>(FV lhs, FV rhs)                            \
  {                                                                            \
    return lhs.m_val <=> rhs.m_val;                                            \
  }
BASED_BUILDER_DECORATOR(Ordered)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator+=(FV rhs)                                           \
  {                                                                            \
    this->m_val += rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator+(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val + rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Addable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator-=(FV rhs)                                           \
  {                                                                            \
    this->m_val -= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator-(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val - rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Subtractable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator*=(FV rhs)                                           \
  {                                                                            \
    this->m_val *= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator*(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val * rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Multipliable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator/=(FV rhs)                                           \
  {                                                                            \
    this->m_val /= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator/(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val / rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Divisible)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator%=(FV rhs)                                           \
  {                                                                            \
    this->m_val %= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator%(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val % rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Modable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto& operator++(FV& lhs)                                   \
  {                                                                            \
    ++lhs.value;                                                               \
    return lhs;                                                                \
  }
BASED_BUILDER_DECORATOR(PreIncrementable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto operator++(FV lhs, int)                                \
  {                                                                            \
    return FV(lhs.m_val++);                                                    \
  }
BASED_BUILDER_DECORATOR(PostIncrementable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto& operator--(FV& lhs)                                   \
  {                                                                            \
    --lhs.value;                                                               \
    return lhs;                                                                \
  }
BASED_BUILDER_DECORATOR(PreDecrementable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto operator--(FV lhs, int)                                \
  {                                                                            \
    return FV(lhs.m_val--);                                                    \
  }
BASED_BUILDER_DECORATOR(PostDecrementable)
#undef X

#define X(FV, Name)                                                            \
  friend constexpr auto operator~(FV rhs)                                      \
  {                                                                            \
    return FV(~rhs.m_val);                                                     \
  }
BASED_BUILDER_DECORATOR(Notable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator&=(FV rhs)                                           \
  {                                                                            \
    this->m_val &= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator&(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val & rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Andable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator|=(FV rhs)                                           \
  {                                                                            \
    this->m_val |= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator|(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val | rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Orable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator^=(FV rhs)                                           \
  {                                                                            \
    this->m_val ^= rhs.m_val;                                                  \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator^(FV lhs, FV rhs)                              \
  {                                                                            \
    return FV(lhs.m_val ^ rhs.m_val);                                          \
  }
BASED_BUILDER_DECORATOR(Xorable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator<<=(FV rhs)                                          \
  {                                                                            \
    this->m_val <<= rhs.m_val;                                                 \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator<<(FV lhs, FV rhs)                             \
  {                                                                            \
    return FV(lhs.m_val << rhs.m_val);                                         \
  }
BASED_BUILDER_DECORATOR(LShiftable)
#undef X

#define X(FV, Name)                                                            \
  constexpr auto& operator>>=(FV rhs)                                          \
  {                                                                            \
    this->m_val >>= rhs.m_val;                                                 \
    return *this;                                                              \
  }                                                                            \
  friend constexpr auto operator>>(FV lhs, FV rhs)                             \
  {                                                                            \
    return FV(lhs.m_val >> rhs.m_val);                                         \
  }
BASED_BUILDER_DECORATOR(RShiftable)
#undef X

}  // namespace based

// NOLINTEND(*macro-usage*,*macro-parentheses*,*naming*)
