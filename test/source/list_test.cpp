#include <numeric>

#include "based/list.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/types/literals.hpp"

template class based::list_pool<based::u8, based::u8>;

// NOLINTBEGIN(*complexity*)

TEST_CASE("list_pool", "[list/list_pool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using list_pool = based::list_pool<based::u8, based::u8>;

  auto pool = list_pool();
  auto head = pool.node_empty();

  SECTION("node_empty is empty")
  {
    REQUIRE(pool.is_empty(head) == true);
    REQUIRE(pool.node_empty() == head);
  }

  SECTION("add one node")
  {
    head = pool.allocate(1_u8, head);

    REQUIRE(pool.is_empty(head) == false);
    REQUIRE(pool.value(head) == 1_u8);

    REQUIRE(pool.next(head) == pool.node_empty());

    SECTION("add two nodes")
    {
      head = pool.allocate(2_u8, head);

      REQUIRE(pool.is_empty(head) == false);
      REQUIRE(pool.value(head) == 2_u8);

      REQUIRE(pool.value(pool.next(head)) == 1_u8);
      REQUIRE(pool.next(pool.next(head)) == pool.node_empty());

      head = pool.free(head);
    }

    SECTION("alloc after free")
    {
      head = pool.allocate(2_u8, head);
      head = pool.free(head);
      head = pool.allocate(3_u8, head);

      REQUIRE(pool.is_empty(head) == false);
      REQUIRE(pool.value(head) == 3_u8);

      head = pool.free(head);
    }

    head = pool.free(head);
  }

  REQUIRE(pool.is_empty(head) == true);
  REQUIRE(pool.node_empty() == head);
}

TEST_CASE("list_pool iterator", "[list/list_pool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using list_pool = based::list_pool<based::u8, based::u8>;

  auto pool = list_pool();
  auto head = pool.node_empty();

  static constexpr auto iter_count = 255_u8;
  for (auto i = 0_u8; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("for-loop")
  {
    using iter = list_pool::iterator;

    auto sum = 0_u32;
    for (auto it = iter(pool, head); it != iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 255_u32 * 254_u32);
  }

  SECTION("accumulate")
  {
    using iter = list_pool::iterator;

    const auto sum = std::accumulate(
        iter(pool, head),
        iter(pool),
        based::u32 {0},
        [](auto a, auto b)
        {
          return a + b;
        }
    );

    REQUIRE(sum == 255_u32 * 254_u32 / 2_u32);
  }

  based::free_list(pool, head);
}

TEST_CASE("list_pool const iterator", "[list/list_pool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using list_pool = based::list_pool<based::u8, based::u8>;

  auto pool = list_pool();
  auto head = pool.node_empty();

  static constexpr auto iter_count = 255_u8;
  for (auto i = 0_u8; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("const for-loop")
  {
    using iter = list_pool::const_iterator;

    auto sum = 0_u32;
    for (auto it = iter(pool, head); it != iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 255_u32 * 254_u32);
  }

  SECTION("const accumulate")
  {
    using iter = list_pool::const_iterator;

    static const auto sum =
        [](const list_pool& lpool, const list_pool::list_type& lhead)
    {
      return std::accumulate(
          iter(lpool, lhead),
          iter(lpool),
          based::u32 {0},
          [](auto a, auto b)
          {
            return a + b;
          }
      );
    };

    REQUIRE(sum(pool, head) == 255_u32 * 254_u32 / 2_u32);
  }

  based::free_list(pool, head);
}

TEST_CASE("list_pool queue", "[list/list_pool/queue]")
{
  using list_pool = based::list_pool<based::u8, based::u8>;
  using iter = list_pool::iterator;

  auto pool = list_pool();
  auto queue = pool.queue_empty();

  SECTION("free(empty, empty)")
  {
    REQUIRE(pool.free(queue.first, queue.second) == pool.node_empty());
  }

  SECTION("pop_front(empty)")
  {
    REQUIRE(pool.pop_front(queue) == queue);
  }

  SECTION("operation")
  {
    using namespace based::literals;  // NOLINT(*namespace*)
    static constexpr auto iter_count = 255_u8;
    for (auto i = 0_u8; i < iter_count; i++) {
      if (i % 2_u8 == 0_u8) {
        queue = pool.push_front(queue, i);
      } else {
        queue = pool.push_back(queue, i);
      }

      if (i % 3_u8 == 0_u8) {
        queue = pool.pop_front(queue);
      }
    }

    auto sum = 0_u64;
    for (auto it = iter(pool, queue.first); it != iter(pool); ++it) {
      sum += *it;
    }

    pool.free(queue);

    REQUIRE(sum == 21717_u64);
  }
}

// NOLINTEND(*complexity*)
