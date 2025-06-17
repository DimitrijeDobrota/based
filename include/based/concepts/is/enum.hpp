#pragma once

#include "based/trait/is/enum.hpp"

namespace based
{

namespace detail
{

void test_conversion(...);  // selected when E is complete and scoped
void test_conversion(int) = delete;  // selected when E is complete and unscoped

}  // namespace detail

template<class T>
concept IsEnum = is_enum_v<T>;

template<class T>
concept IsScopedEnum = requires {
  requires(IsEnum<T>);
  {
    detail::test_conversion(T {})
  };
};

}  // namespace based
