#include <numeric>

#include "based/container/list.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/integral/literals.hpp"

template class based::ListPool<based::U8, based::U8>;

// NOLINTBEGIN(*complexity*)

TEST_CASE("ListPool", "[container/ListPool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using ListPool = based::ListPool<based::U8, based::U8>;

  auto pool = ListPool();
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

TEST_CASE("ListPool iterator", "[container/ListPool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using ListPool = based::ListPool<based::U8, based::U8>;

  auto pool = ListPool();
  auto head = pool.node_empty();

  static constexpr auto iter_count = 255_u8;
  for (auto i = 0_u8; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("for-loop")
  {
    using Iter = ListPool::Iterator;

    auto sum = 0_U32;
    for (auto it = Iter(pool, head); it != Iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 255_U32 * 254_U32);
  }

  SECTION("accumulate")
  {
    using Iter = ListPool::Iterator;

    const auto sum = std::accumulate(
        Iter(pool, head),
        Iter(pool),
        based::U32 {0},
        [](auto a, auto b)
        {
          return a + b;
        }
    );

    REQUIRE(sum == 255_U32 * 254_U32 / 2_U32);
  }

  based::free_list(pool, head);
}

TEST_CASE("ListPool const iterator", "[container/ListPool]")
{
  using namespace based::literals;  // NOLINT(*namespace*)
  using ListPool = based::ListPool<based::U8, based::U8>;

  auto pool = ListPool();
  auto head = pool.node_empty();

  static constexpr auto iter_count = 255_u8;
  for (auto i = 0_u8; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("const for-loop")
  {
    using Iter = ListPool::ConstIterator;

    auto sum = 0_U32;
    for (auto it = Iter(pool, head); it != Iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 255_U32 * 254_U32);
  }

  SECTION("const accumulate")
  {
    using Iter = ListPool::ConstIterator;

    static const auto sum =
        [](const ListPool& lpool, const ListPool::ListType& lhead)
    {
      return std::accumulate(
          Iter(lpool, lhead),
          Iter(lpool),
          based::U32 {0},
          [](auto a, auto b)
          {
            return a + b;
          }
      );
    };

    REQUIRE(sum(pool, head) == 255_U32 * 254_U32 / 2_U32);
  }

  based::free_list(pool, head);
}

TEST_CASE("ListPool queue", "[container/ListPool/queue]")
{
  using ListPool = based::ListPool<based::U8, based::U8>;
  using Iter = ListPool::Iterator;

  auto pool = ListPool();
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

    auto sum = 0_U64;
    for (auto it = Iter(pool, queue.first); it != Iter(pool); ++it) {
      sum += *it;
    }

    pool.free(queue);

    REQUIRE(sum == 21717_U64);
  }
}

// NOLINTEND(*complexity*)
