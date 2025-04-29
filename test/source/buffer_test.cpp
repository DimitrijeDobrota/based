#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/template.hpp"

template struct based::buffer<sizeof(void*)>;

TEST_CASE("valid type", "[template/buffer]")
{
  SECTION("small buffer")
  {
    using buffer = based::buffer<sizeof(std::uint8_t)>;
    STATIC_REQUIRE(buffer::valid_type<std::uint8_t>());
    STATIC_REQUIRE_FALSE(buffer::valid_type<std::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT array
  }

  SECTION("big buffer")
  {
    using buffer = based::buffer<sizeof(std::size_t), alignof(std::size_t)>;
    STATIC_REQUIRE(buffer::valid_type<std::uint8_t>());
    STATIC_REQUIRE(buffer::valid_type<std::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT array
  }
}

TEST_CASE("buffer", "[template/buffer]")
{
  using buffer = based::buffer<sizeof(std::size_t)>;

  static constexpr std::uint8_t value = 8;
  buffer buf(std::in_place_type<std::uint8_t>, value);

  REQUIRE(*buf.as<std::uint8_t>() == value);

  SECTION("emplace")
  {
    static constexpr std::uint16_t new_value = 10;
    buf.emplace<std::uint16_t>(new_value);

    REQUIRE(*buf.as<std::uint16_t>() == new_value);
  }

  SECTION("swap")
  {
    static constexpr std::uint16_t new_value = 10;
    buffer new_buf(std::in_place_type<std::uint16_t>, new_value);
    buf.swap(new_buf);

    REQUIRE(*buf.as<std::uint16_t>() == new_value);
    REQUIRE(*new_buf.as<std::uint8_t>() == value);
  }
}

TEST_CASE("const buffer", "[template/buffer]")
{
  using buffer = based::buffer<sizeof(std::size_t)>;

  static constexpr std::uint8_t value = 8;
  const buffer buf(std::in_place_type<std::uint8_t>, value);

  REQUIRE(*buf.as<std::uint8_t>() == value);
}
