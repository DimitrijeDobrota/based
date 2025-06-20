#include "based/functional/function.hpp"

#include <catch2/catch_test_macros.hpp>

namespace
{

int identity(int a)
{
  return a;
}

}  // namespace

template class based::Function<decltype(identity)>;

TEST_CASE("empty", "[template/function]")
{
  const based::Function<void()> func;

  try {
    func();
    REQUIRE(false);
  } catch (const std::bad_function_call& err) {
    REQUIRE(true);
  } catch (...) {
    REQUIRE(false);
  }
}

TEST_CASE("free function", "[template/function]")
{
  const based::Function func = identity;

  REQUIRE(func(3) == 3);
}

TEST_CASE("lambda function", "[template/function]")
{
  const based::Function func = [](int a)
  {
    return a;
  };

  REQUIRE(func(3) == 3);
}
