#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/character/mapper.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/character/type.hpp"

struct test
{
  constexpr bool operator()(based::character chr) const { return chr >= '\0'; }
};

template class based::mapper<test>;

TEST_CASE("mapper", "[character/mapper]")
{
  REQUIRE(true);
}
