#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/concepts/is/same.hpp"
#include "based/trait/invoke/result.hpp"

int func(double);

template<class Res, class T, class... Args>
concept test = based::SameAs<based::invoke_result_t<T(Args...)>, Res>;

TEST_CASE("invoke_result", "[trait/invoke_result]")
{
  // NOLINTBEGIN(*array*)
  // clang-format off
  /*
  STATIC_REQUIRE(test<int, decltype(func), double>);
  STATIC_REQUIRE(test<int, decltype(func), int>);
  STATIC_REQUIRE(!test<int, decltype(func), char>);
  */
  // clang-format on
  // NOLINTEND(*array*)
}
