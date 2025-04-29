#include <catch2/catch_test_macros.hpp>

#include "based/template.hpp"

namespace
{

int identity(int a)
{
  return a;
}

}  // namespace

template class based::function<decltype(identity)>;

TEST_CASE("empty", "[template/function]")
{
  const based::function<void()> func;

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
  const based::function func = identity;

  REQUIRE(func(3) == 3);
}

TEST_CASE("lambda function", "[template/function]")
{
  const based::function func = [](int a)
  {
    return a;
  };

  REQUIRE(func(3) == 3);
}
