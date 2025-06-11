#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <string>

#include "based/utility/static_view.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("valid type", "[utility/to_string_view]")
{
  static constexpr auto test = based::to_string_view(
      []() consteval
      {
        std::string res;

        const auto start = 65;
        const auto end = 122;
        for (int i = start; i < end; i++) {
          if (i % 2 == 1) {
            res += static_cast<char>('\0' + i);
          }
        }

        return res;
      }
  );

  STATIC_REQUIRE(test == "ACEGIKMOQSUWY[]_acegikmoqsuwy");
}
