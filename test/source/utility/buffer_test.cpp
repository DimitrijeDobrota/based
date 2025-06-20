#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/utility/buffer.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"

template struct based::Buffer<sizeof(void*)>;

TEST_CASE("valid type", "[utility/buffer]")
{
  SECTION("small buffer")
  {
    using Buffer = based::Buffer<sizeof(based::U8)>;
    STATIC_REQUIRE(Buffer::valid_type<based::U8>());
    STATIC_REQUIRE_FALSE(Buffer::valid_type<based::SizeT>());

    STATIC_REQUIRE_FALSE(Buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }

  SECTION("big buffer")
  {
    using Buffer = based::Buffer<sizeof(based::SizeT), alignof(based::SizeT)>;
    STATIC_REQUIRE(Buffer::valid_type<based::U8>());
    STATIC_REQUIRE(Buffer::valid_type<based::SizeT>());

    STATIC_REQUIRE_FALSE(Buffer::valid_type<char[5]>());  // NOLINT(*array*)
  }
}

TEST_CASE("buffer", "[utility/buffer]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using Buffer = based::Buffer<sizeof(based::SizeT)>;

  static constexpr auto value = 8_u8;
  Buffer buf(std::in_place_type<based::U8>, value);

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
    Buffer new_buf(std::in_place_type<based::U16>, new_value);
    buf.swap(new_buf);

    REQUIRE(*buf.as<based::U16>() == new_value);
    REQUIRE(*new_buf.as<based::U8>() == value);
  }
}

TEST_CASE("const buffer", "[utility/buffer]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using Buffer = based::Buffer<sizeof(based::SizeT)>;

  static constexpr auto value = 8_u8;
  const Buffer buf(std::in_place_type<based::U8>, value);

  REQUIRE(*buf.as<based::U8>() == value);
}
