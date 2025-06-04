#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/char/mapper.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/char/character.hpp"

struct test
{
  constexpr bool operator()(based::character chr) const { return chr >= '\0'; }
};

template class based::mapper<test>;

TEST_CASE("mapper", "[char/mapper]")
{
  REQUIRE(true);
}
