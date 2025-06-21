// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/concept/callable.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is_same.hpp"

namespace
{

// NOLINTNEXTLINE(*need*)
int free_func(int a, double b)
{
  return static_cast<int>(a + b);
}

}  // namespace

using based::trait::IsSame;

TEST_CASE("free function", "[concept/IsCallable]")
{
  using TypeT = decltype(free_func);

  STATIC_REQUIRE(based::trait::IsCallable<TypeT>);
  STATIC_REQUIRE(IsSame<based::trait::CallableSigT<TypeT>, int(int, double)>);
  STATIC_REQUIRE(IsSame<based::trait::CallableRetT<TypeT>, int>);
}

TEST_CASE("lambda", "[concept/IsCallable]")
{
  const auto func = [](int a, double b)
  {
    return static_cast<int>(a + b);
  };
  using TypeT = decltype(func);

  STATIC_REQUIRE(based::trait::IsCallable<TypeT>);
  STATIC_REQUIRE(IsSame<based::trait::CallableSigT<TypeT>, int(int, double)>);
  STATIC_REQUIRE(IsSame<based::trait::CallableRetT<TypeT>, int>);
}

struct Func
{
  auto operator()(auto a, auto b) { return static_cast<int>(a + b); }
};

/*
TEST_CASE("member function", "[concept/IsCallable]")
{
  // [&](auto&&... args) -> decltype(auto) { return
  // f(based::forward<decltype(args)>(args)...); }

  // based::error_template<decltype(&func::template operator()<int, double>)>();
  STATIC_REQUIRE(based::IsCallable<Func>);
  STATIC_REQUIRE(IsSame<based::CallableSigT<Func>, int(int, double)>);
  STATIC_REQUIRE(IsSame<based::CallableRetT<Func>, int>);
}
*/
