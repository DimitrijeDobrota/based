#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/invoke_result.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"

namespace
{

// NOLINTNEXTLINE(*needed*)
int func(double);

}  // namespace

template<class Res, class T, class... Args>
concept Test = based::SameAs<based::invoke_result_t<T, Args...>, Res>;

TEST_CASE("invoke_result", "[trait/invoke_result]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off

  STATIC_REQUIRE(Test<int, decltype(func), double>);
  STATIC_REQUIRE(Test<int, decltype(func), int>);
  STATIC_REQUIRE(!Test<int, decltype(func), decltype(func)>);

  // clang-format on
  // NOLINTEND(*array*)
}
