// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/callable.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
#include "based/trait/remove_extent.hpp"

namespace
{

// NOLINTNEXTLINE(*need*)
int free_func(int a, double b)
{
  return static_cast<int>(a + b);
}

}  // namespace

using based::SameAs;

TEST_CASE("free function", "[concept/callable]")
{
  using TypeT = decltype(free_func);

  STATIC_REQUIRE(based::Callable<TypeT>);
  STATIC_REQUIRE(SameAs<based::CallableSigT<TypeT>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::CallableRetT<TypeT>, int>);
}

TEST_CASE("lambda", "[concept/callable]")
{
  const auto func = [](int a, double b)
  {
    return static_cast<int>(a + b);
  };
  using TypeT = decltype(func);

  STATIC_REQUIRE(based::Callable<TypeT>);
  STATIC_REQUIRE(SameAs<based::CallableSigT<TypeT>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::CallableRetT<TypeT>, int>);
}

struct Func
{
  auto operator()(auto a, auto b) { return static_cast<int>(a + b); }
};

/*
TEST_CASE("member function", "[concept/callable]")
{
  // [&](auto&&... args) -> decltype(auto) { return
  // f(based::forward<decltype(args)>(args)...); }

  // based::error_template<decltype(&func::template operator()<int, double>)>();
  STATIC_REQUIRE(based::Callable<Func>);
  STATIC_REQUIRE(SameAs<based::CallableSigT<Func>, int(int, double)>);
  STATIC_REQUIRE(SameAs<based::CallableRetT<Func>, int>);
}
*/
