#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/utility/buffer.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/types/types.hpp"

template struct based::buffer<sizeof(void*)>;

TEST_CASE("valid type", "[template/buffer]")
{
  SECTION("small buffer")
  {
    using buffer = based::buffer<sizeof(based::u8)>;
    STATIC_REQUIRE(buffer::valid_type<based::u8>());
    STATIC_REQUIRE_FALSE(buffer::valid_type<based::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }

  SECTION("big buffer")
  {
    using buffer = based::buffer<sizeof(based::size_t), alignof(based::size_t)>;
    STATIC_REQUIRE(buffer::valid_type<based::u8>());
    STATIC_REQUIRE(buffer::valid_type<based::size_t>());

    STATIC_REQUIRE_FALSE(buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }
}

TEST_CASE("buffer", "[template/buffer]")
{
  using buffer = based::buffer<sizeof(based::size_t)>;

  static constexpr based::u8 value = 8;
  buffer buf(std::in_place_type<based::u8>, value);

  REQUIRE(*buf.as<based::u8>() == value);

  SECTION("emplace")
  {
    static constexpr based::u16 new_value = 10;
    buf.emplace<based::u16>(new_value);

    REQUIRE(*buf.as<based::u16>() == new_value);
  }

  SECTION("swap")
  {
    static constexpr based::u16 new_value = 10;
    buffer new_buf(std::in_place_type<based::u16>, new_value);
    buf.swap(new_buf);

    REQUIRE(*buf.as<based::u16>() == new_value);
    REQUIRE(*new_buf.as<based::u8>() == value);
  }
}

TEST_CASE("const buffer", "[template/buffer]")
{
  using buffer = based::buffer<sizeof(based::size_t)>;

  static constexpr based::u8 value = 8;
  const buffer buf(std::in_place_type<based::u8>, value);

  REQUIRE(*buf.as<based::u8>() == value);
}
