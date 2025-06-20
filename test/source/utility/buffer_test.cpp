#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/utility/buffer.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"

template struct based::Buffer<sizeof(void*)>;

TEST_CASE("valid type", "[utility/buffer]")
{
  SECTION("small buffer")
  {
    using buffer = based::Buffer<sizeof(based::U8)>;
    STATIC_REQUIRE(buffer::valid_type<based::U8>());
    STATIC_REQUIRE_FALSE(buffer::valid_type<based::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }

  SECTION("big buffer")
  {
    using buffer = based::Buffer<sizeof(based::size_t), alignof(based::size_t)>;
    STATIC_REQUIRE(buffer::valid_type<based::U8>());
    STATIC_REQUIRE(buffer::valid_type<based::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }
}

TEST_CASE("buffer", "[utility/buffer]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using buffer = based::Buffer<sizeof(based::size_t)>;

  static constexpr auto value = 8_u8;
  buffer buf(std::in_place_type<based::U8>, value);

  REQUIRE(*buf.as<based::U8>() == value);

  SECTION("emplace")
  {
    static constexpr auto new_value = 10_U16;
    buf.emplace<based::U16>(new_value);

    REQUIRE(*buf.as<based::U16>() == new_value);
  }

  SECTION("swap")
  {
    static constexpr auto new_value = 10_U16;
    buffer new_buf(std::in_place_type<based::U16>, new_value);
    buf.swap(new_buf);

    REQUIRE(*buf.as<based::U16>() == new_value);
    REQUIRE(*new_buf.as<based::U8>() == value);
  }
}

TEST_CASE("const buffer", "[utility/buffer]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using buffer = based::Buffer<sizeof(based::size_t)>;

  static constexpr auto value = 8_u8;
  const buffer buf(std::in_place_type<based::U8>, value);

  REQUIRE(*buf.as<based::U8>() == value);
}
