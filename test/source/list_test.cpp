#include <numeric>

#include "based/list.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/types/types.hpp"

template class based::list_pool<based::u8, based::u8>;

TEST_CASE("list_pool", "[list/list_pool]")
{
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
    head = pool.allocate(1, head);

    REQUIRE(pool.is_empty(head) == false);
    REQUIRE(pool.value(head) == 1);

    REQUIRE(pool.next(head) == pool.node_empty());

    SECTION("add two nodes")
    {
      head = pool.allocate(2, head);

      REQUIRE(pool.is_empty(head) == false);
      REQUIRE(pool.value(head) == 2);

      REQUIRE(pool.value(pool.next(head)) == 1);
      REQUIRE(pool.next(pool.next(head)) == pool.node_empty());

      head = pool.free(head);
    }

    SECTION("alloc after free")
    {
      head = pool.allocate(2, head);
      head = pool.free(head);
      head = pool.allocate(3, head);

      REQUIRE(pool.is_empty(head) == false);
      REQUIRE(pool.value(head) == 3);

      head = pool.free(head);
    }

    head = pool.free(head);
  }

  REQUIRE(pool.is_empty(head) == true);
  REQUIRE(pool.node_empty() == head);
}

TEST_CASE("list_pool iterator", "[list/list_pool]")
{
  using list_pool = based::list_pool<based::u8, based::u8>;

  auto pool = list_pool();
  auto head = pool.node_empty();

  static constexpr based::size_t iter_count = 0xFF;
  for (based::u8 i = 0; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("for-loop")
  {
    using iter = list_pool::iterator;

    based::u32 sum = 0;
    for (auto it = iter(pool, head); it != iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 0xFF * 0xFE);
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

    REQUIRE(sum == 0xFF * 0xFE / 2);
  }

  based::free_list(pool, head);
}

TEST_CASE("list_pool const iterator", "[list/list_pool]")
{
  using list_pool = based::list_pool<based::u8, based::u8>;

  auto pool = list_pool();
  auto head = pool.node_empty();

  static constexpr based::size_t iter_count = 0xFF;
  for (based::u8 i = 0; i < iter_count; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("const for-loop")
  {
    using iter = list_pool::const_iterator;

    based::u32 sum = 0;
    for (auto it = iter(pool, head); it != iter(pool); it++) {
      sum += *it.operator->();
      sum += *it;
    }

    REQUIRE(sum == 0xFF * 0xFE);
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

    REQUIRE(sum(pool, head) == 0xFF * 0xFE / 2);
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

  static constexpr based::size_t iter_count = 0xFF;
  for (based::u8 i = 0; i < iter_count; i++) {
    if (i % 2 == 0) {
      queue = pool.push_front(queue, i);
    } else {
      queue = pool.push_back(queue, i);
    }

    if (i % 3 == 0) {
      queue = pool.pop_front(queue);
    }
  }

  based::u64 sum = 0;
  for (auto it = iter(pool, queue.first); it != iter(pool); ++it) {
    sum += *it;
  }

  pool.free(queue);

  REQUIRE(sum == 21717);
}
