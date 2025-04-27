#include <numeric>

#include "based/list.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("list_pool", "[list/list_pool]")
{
  using list_pool = based::list_pool<std::uint8_t, std::uint8_t>;

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

TEST_CASE("list_pool iterator", "[list/list_pool/iterator]")
{
  using list_pool = based::list_pool<std::uint8_t, std::uint8_t>;
  using iter = list_pool::iterator;

  auto pool = list_pool();
  auto head = pool.node_empty();

  for (std::uint8_t i = 0; i < 0xFF; i++) {
    head = pool.allocate(i, head);
  }

  SECTION("for-loop")
  {
    std::uint64_t sum = 0;
    for (auto it = iter(pool, head); it != iter(pool); ++it) {
      sum += *it;
    }

    REQUIRE(sum == 0xFF * 0xFE / 2);
  }

  SECTION("accumulate")
  {
    const auto sum = std::accumulate(
        iter(pool, head),
        iter(pool),
        std::uint64_t {0},
        [](auto a, auto b)
        {
          return a + b;
        }
    );

    REQUIRE(sum == 0xFF * 0xFE / 2);
  }

  based::free_list(pool, head);
}

TEST_CASE("list_pool queue", "[list/list_pool/queue]")
{
  using list_pool = based::list_pool<std::uint8_t, std::uint8_t>;
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

  for (std::uint8_t i = 0; i < 0xFF; i++) {
    if (i % 2 == 0) {
      queue = pool.push_front(queue, i);
    } else {
      queue = pool.push_back(queue, i);
    }

    if (i % 3 == 0) {
      queue = pool.pop_front(queue);
    }
  }

  std::uint64_t sum = 0;
  for (auto it = iter(pool, queue.first); it != iter(pool); ++it) {
    sum += *it;
  }

  pool.free(queue);

  REQUIRE(sum == 21717);
}
