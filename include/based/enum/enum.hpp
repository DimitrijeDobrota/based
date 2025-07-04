#pragma once

#include "based/algorithm/clamp.hpp"
#include "based/concept/is_enum.hpp"
#include "based/concept/is_same.hpp"

namespace based::enumeration
{

namespace category
{

/*
 * The default enumeration category
 *
 * Conversion is equivalent to static_cast
 * Unspecified enum_traits use this category
 */
struct Def
{
};

/*
 * The standard enumeration category
 *
 * Values outside the given range are mapped to a given none-element
 *
 * Requires:
 *  - If both Enum::min and Enum::max are given, then Enum::min <= Enum::max
 *  - Enum::none must be given, and !(Enum::min <= Enum::none <= Enum::max)
 * Enum::min and Enum::max default to min/max value of the underlying type
 *
 * Additional operators:
 *  - operator!
 */
struct Standard
{
};

/*
 * The linear enumeration category
 *
 * Values outside the given range are clipped to the given range
 *
 * Requires:
 *  - If both Enum::min and Enum::max are given, then Enum::min <= Enum::max
 *  - Enum::none must be given, and !(Enum::min <= Enum::none <= Enum::max)
 * Enum::min and Enum::max default to min/max value of the underlying type
 *
 * Additional operators:
 *  - operator!
 *  - operator++
 *  - operator--
 */
struct Linear
{
};

/*
 * The bitmask enumeration category
 *
 * Bits common to the given range limits are kept constant
 *
 * Requires:
 *  - If both Enum::min and Enum::max are given, all of the bits set in
 * Enum::min must also be set in Enum::max
 *  - The underlying type of Enum must be unsigned
 * Enum::min and Enum::max default to min/max value of the underlying type
 *
 * Additional operators:
 *  - operator&
 *  - operator&=
 *  - operator|
 *  - operator|=
 *  - operator^
 *  - operator^=
 *  - operator~
 */
struct Bitmask
{
};

/*
 * The descrete enumeration category
 *
 * Values not equal to any of the given template parameters are mapped to the
 * given none-element
 *
 * Requires:
 *  - Enum::none must be given, and vals... must contain Enum::none
 * Enum::min and Enum::max default to min/max value of the underlying type
 *
 * Additional operators:
 *  - operator!
 */
template<class Enum, Enum... vals>
struct Discrete
{
};

}  // namespace category

namespace enum_traits
{

/*
 * Enumeration traits class template
 *
 * Requires:
 *  - trait::IsScopedEnum<T>
 *
 * Contains:
 *  - category_type: The Enumeration category used for this type
 *  - value_type: The underlying type for this type
 */
template<class T>
  requires trait::IsScopedEnum<T>
// TODO: check for proper int type
struct Traits
{
  /* TODO (provide defaults)
  using category = enum_default;
  using value_type = based::u8;
  */
};

template<class Enum>
concept HasCategory = requires { typename Traits<Enum>::category; };

template<class Enum>
concept HasValueType = requires { typename Traits<Enum>::value_type; };

template<HasCategory Enum>
using CategoryType = typename Traits<Enum>::category;

template<HasValueType Enum>
using value_type = typename Traits<Enum>::value_type;

template<HasValueType Enum>
using BasicType = typename Traits<Enum>::value_type::underlying_type;

template<class Enum>
concept HasNone = requires {
  {
    Enum::none
  };
};

template<class Enum>
concept HasMin = requires {
  {
    Enum::min
  };
};

template<class Enum>
concept HasMax = requires {
  {
    Enum::max
  };
};

template<HasNone Enum>
static constexpr Enum none = Enum::none;

template<HasMin Enum>
static constexpr Enum min = Enum::min;

template<HasMin Enum>
static constexpr Enum max = Enum::max;

template<class Enum, class Category>
concept IsCategory = requires {
  requires(HasCategory<Enum>);
  requires(trait::IsSame<Category, CategoryType<Enum>>);
};

template<class Enum>
concept IsDefault = IsCategory<Enum, category::Def>;

template<class Enum>
concept IsStandard = requires {
  requires(IsCategory<Enum, category::Standard>);
  requires(HasNone<Enum>);
  requires(
      !HasMin<Enum> || !HasMin<Enum>
      || !(min<Enum> <= none<Enum> && none<Enum> <= max<Enum>)
  );
};

template<class Enum>
concept IsLinear = requires {
  requires(IsCategory<Enum, category::Linear>);
  requires(HasNone<Enum>);
  requires(
      !HasMin<Enum> || !HasMin<Enum>
      || !(min<Enum> <= none<Enum> && none<Enum> <= max<Enum>)
  );
};

template<class Enum>
concept IsBitmask = requires {
  requires(IsCategory<Enum, category::Bitmask>);
  requires(HasMin<Enum>);
  requires(HasMin<Enum>);
};

}  // namespace enum_traits

namespace detail
{

template<class T>
// TODO: requires T to be unsigned
constexpr T bitwise_clamp(T value, T low, T high) noexcept
{
  return (value & high) | low;
}

template<class T>
constexpr T clamp(T value, T low, T high) noexcept
{
  return based::clamp(value, low, high);
}

template<class Enum>
constexpr enum_traits::value_type<Enum> value_cast_impl(Enum value) noexcept
{
  return static_cast<enum_traits::value_type<Enum>>(
      static_cast<enum_traits::BasicType<Enum>>(value)
  );
}

template<class Enum>
constexpr Enum enum_cast_impl(enum_traits::value_type<Enum> value) noexcept
{
  // NOLINTNEXTLINE(*EnumCastOutOfRange*)
  return static_cast<Enum>(static_cast<enum_traits::BasicType<Enum>>(value));
}

}  // namespace detail

namespace category_traits
{

/*
 * Enumeration category traits class template
 *
 * Contains:
 *  - typename category
 *  - template<class Enum> static bool valid()
 *      Check during compile-time whether the given enumeration type satisfies
 *      the category's constraints
 *  - template<class Enum> static Enum enum_cast(traits::value_type<Enum>)
 *      Maps a given value to the enumeration type
 */
template<class Category>
struct Traits;

template<>
struct Traits<category::Def>
{
  using Category = category::Def;

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr bool valid() noexcept
  {
    return true;
  }

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr Enum enum_cast(enum_traits::value_type<Enum> value) noexcept
  {
    return static_cast<Enum>(value);
  }
};

template<>
struct Traits<category::Standard>
{
  using Category = category::Standard;

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr bool valid() noexcept
  {
    if constexpr (enum_traits::HasNone<Enum>) {
      constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
      constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
      constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);
      return xmin <= xmax && xnone != detail::clamp(xnone, xmin, xmax);
    }

    return false;
  }

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr Enum enum_cast(enum_traits::value_type<Enum> value) noexcept
  {
    constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
    constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
    constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);
    return detail::enum_cast_impl<Enum>(
        value == detail::clamp(value, xmin, xmax) ? value : xnone
    );
  }
};

template<>
struct Traits<category::Linear>
{
  using Category = category::Linear;

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr bool valid() noexcept
  {
    if constexpr (enum_traits::HasNone<Enum>) {
      constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
      constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
      constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);
      return xmin <= xmax && xnone != detail::clamp(xnone, xmin, xmax);
    } else {
      return false;
    }
  }

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr Enum enum_cast(enum_traits::value_type<Enum> x) noexcept
  {
    constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
    constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
    constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);
    return detail::enum_cast_impl<Enum>(
        x == xnone ? xnone : detail::clamp(x, xmin, xmax)
    );
  }
};

template<>
struct Traits<category::Bitmask>
{
  using Category = category::Bitmask;

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr bool valid() noexcept
  {
    constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
    constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);

    if constexpr ((xmin & xmax) == xmin) {
      if constexpr (enum_traits::HasNone<Enum>) {
        constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
        return xnone != detail::bitwise_clamp(xnone, xmin, xmax);
      }
      return true;
    }

    return false;
  }

  template<enum_traits::IsCategory<Category> Enum>
  static constexpr Enum enum_cast(enum_traits::value_type<Enum> value) noexcept
  {
    constexpr auto xmin = detail::value_cast_impl(enum_traits::min<Enum>);
    constexpr auto xmax = detail::value_cast_impl(enum_traits::max<Enum>);

    if constexpr (!enum_traits::HasNone<Enum>) {
      return detail::enum_cast_impl<Enum>(
          detail::bitwise_clamp<decltype(xmin)>(value, xmin, xmax)
      );
    } else {
      constexpr auto xnone = detail::value_cast_impl(enum_traits::none<Enum>);
      return detail::enum_cast_impl<Enum>(
          value == xnone
              ? xnone
              : detail::bitwise_clamp<decltype(xmin)>(value, xmin, xmax)
      );
    }
  }
};

template<class Enum, Enum... vals>
struct Traits<category::Discrete<Enum, vals...>>
{
  using Category = category::Discrete<Enum, vals...>;

  template<enum_traits::IsCategory<Category> EnumI>
    requires trait::IsSame<Enum, EnumI>
  static constexpr bool valid() noexcept
  {
    if constexpr (enum_traits::HasNone<Enum>) {
      return !(... || (vals == Enum::none));
    } else {
      return false;
    }
  }

  template<enum_traits::IsCategory<Category> EnumI>
    requires trait::IsSame<Enum, EnumI>
  static constexpr Enum enum_cast(enum_traits::value_type<Enum> value) noexcept
  {
    if ((... || (detail::value_cast_impl(vals) == value))) {
      return detail::enum_cast_impl<Enum>(value);
    }
    return Enum::none;
  }
};

template<class Enum>
static constexpr auto valid() noexcept
{
  return Traits<enum_traits::CategoryType<Enum>>::template valid<Enum>();
}

template<class Enum>
static constexpr auto enum_cast(enum_traits::value_type<Enum> value) noexcept
{
  return Traits<enum_traits::CategoryType<Enum>>::template enum_cast<Enum>(
      value
  );
}

}  // namespace category_traits

template<class Enum>
constexpr enum_traits::value_type<Enum> value_cast(Enum value) noexcept
{
  static_assert(category_traits::valid<Enum>());
  return detail::value_cast_impl(value);
}

template<class Enum>
constexpr Enum enum_cast(enum_traits::value_type<Enum> value) noexcept
{
  static_assert(category_traits::valid<Enum>());
  return category_traits::enum_cast<Enum>(value);
}

template<class Enum>
constexpr Enum enum_cast(Enum value) noexcept
{
  static_assert(category_traits::valid<Enum>());
  return category_traits::enum_cast<Enum>(value_cast<Enum>(value));
}

inline namespace operators
{

template<enum_traits::HasNone Enum>
constexpr bool operator!(const Enum& lhs) noexcept
{
  return lhs == enum_traits::none<Enum>;
}

inline namespace op_inc
{

template<enum_traits::IsLinear Enum>
constexpr Enum& operator++(Enum& lhs) noexcept
{
  if (!(!lhs || lhs == enum_traits::max<Enum>)) {
    lhs = enum_cast<Enum>(value_cast(lhs) + 1);
  }
  return lhs;
}

template<enum_traits::IsLinear Enum>
constexpr Enum operator++(const Enum& lhs, int) noexcept
{
  Enum ret = lhs;
  ++lhs;
  return ret;
}

}  // namespace op_inc

inline namespace op_dec
{

template<enum_traits::IsLinear Enum>
constexpr Enum& operator--(Enum& lhs) noexcept
{
  if (!(!lhs || lhs == enum_traits::min<Enum>)) {
    lhs = enum_cast<Enum>(value_cast(lhs) - 1);
  }
  return lhs;
}

template<enum_traits::IsLinear Enum>
constexpr Enum operator--(const Enum& lhs, int) noexcept
{
  Enum ret = lhs;
  --lhs;
  return ret;
}

}  // namespace op_dec

inline namespace op_or
{

template<enum_traits::IsBitmask Enum>
constexpr Enum operator|(const Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!lhs || !rhs) {
      return enum_traits::none<Enum>;
    }
  }
  return enum_cast<Enum>(value_cast(lhs) | value_cast(rhs));
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& operator|=(Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!(!lhs || !rhs)) {
      return lhs = enum_cast<Enum>(value_cast(lhs) | value_cast(rhs));
    }
  } else {
    return lhs = enum_cast<Enum>(value_cast(lhs) | value_cast(rhs));
  }
  return lhs;
}

}  // namespace op_or

inline namespace op_and
{

template<enum_traits::IsBitmask Enum>
constexpr Enum operator&(const Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!lhs || !rhs) {
      return enum_traits::none<Enum>;
    }
  }
  return enum_cast<Enum>(value_cast(lhs) & value_cast(rhs));
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& operator&=(Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!(!lhs || !rhs)) {
      return lhs = enum_cast<Enum>(value_cast(lhs) & value_cast(rhs));
    }
  } else {
    return lhs = enum_cast<Enum>(value_cast(lhs) & value_cast(rhs));
  }
  return lhs;
}

}  // namespace op_and

inline namespace op_xor
{

template<enum_traits::IsBitmask Enum>
constexpr Enum operator^(const Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!lhs || !rhs) {
      return enum_traits::none<Enum>;
    }
  }
  return enum_cast<Enum>(value_cast(lhs) ^ value_cast(rhs));
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& operator^=(Enum& lhs, const Enum& rhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!(!lhs || !rhs)) {
      return lhs = enum_cast<Enum>(value_cast(lhs) ^ value_cast(rhs));
    }
  } else {
    return lhs = enum_cast<Enum>(value_cast(lhs) ^ value_cast(rhs));
  }
  return lhs;
}

}  // namespace op_xor

inline namespace op_not
{

template<enum_traits::IsBitmask Enum>
constexpr Enum operator~(const Enum& lhs) noexcept
{
  if constexpr (enum_traits::HasNone<Enum>) {
    if (!lhs) {
      return enum_traits::none<Enum>;
    }
  }
  return enum_cast<Enum>(~value_cast(lhs));
}

}  // namespace op_not

inline namespace shorthand
{

template<enum_traits::IsBitmask Enum>
constexpr Enum& set(Enum& lhs, const Enum& rhs) noexcept
{
  return lhs |= rhs;
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& mask(Enum& lhs, const Enum& rhs) noexcept
{
  return lhs &= rhs;
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& tgl(Enum& lhs, const Enum& rhs) noexcept
{
  return lhs ^= rhs;
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& neg(Enum& lhs) noexcept
{
  return lhs = ~lhs;
}

template<enum_traits::IsBitmask Enum>
constexpr Enum& clear(Enum& lhs, const Enum& rhs) noexcept
{
  return lhs &= ~rhs;
}

template<enum_traits::IsBitmask Enum>
constexpr bool test(const Enum& lhs, const Enum& rhs) noexcept
{
  return (lhs & rhs) == rhs;
}

}  // namespace shorthand

}  // namespace operators

}  // namespace based::enumeration

// NOLINTBEGIN(*macro*)

#define BASED_ENUM_TRAITS(Name, Type, Category)                                \
  template<>                                                                   \
  struct based::enumeration::enum_traits::Traits<Name>                         \
  {                                                                            \
    using category = Category;                                                 \
    using value_type = Type;                                                   \
  };

#define BASED_ENUM_TRAITS_STANDARD(Name, Type)                                 \
  BASED_ENUM_TRAITS(Name, Type, based::enumeration::category::Standard)

#define BASED_ENUM_TRAITS_LINEAR(Name, Type)                                   \
  BASED_ENUM_TRAITS(Name, Type, based::enumeration::category::Linear)

#define BASED_ENUM_TRAITS_BITMASK(Name, Type)                                  \
  BASED_ENUM_TRAITS(Name, Type, based::enumeration::category::Bitmask)

#define BASED_ENUM(Name, Type, Category)                                       \
  enum class Name : typename Type::underlying_type

#define BASED_ENUM_STANDARD(Name, Type)                                        \
  BASED_ENUM(Name, Type, based::enumeration::category::Standard)

#define BASED_ENUM_LINEAR(Name, Type)                                          \
  BASED_ENUM(Name, Type, based::enumeration::category::Linear)

#define BASED_ENUM_BITMASK(Name, Type)                                         \
  BASED_ENUM(Name, Type, based::enumeration::category::Bitmask)

// NOLINTEND(*macro*)
