#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/char/mapper.hpp"

#include <catch2/catch_test_macros.hpp>

struct test
{
  constexpr bool operator()(char chr) const { return chr >= '\0'; }
};

template class based::mapper<test>;

TEST_CASE("mapper", "[char/mapper]")
{
  REQUIRE(true);
}
