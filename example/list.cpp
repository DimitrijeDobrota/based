#include <cstdint>

#include "based/list.hpp"

#include "based/instrumentation.hpp"

int main()
{
  using instrumented = based::instrumented<double>;

  based::list_pool<instrumented, std::uint8_t> pool;
  auto head = pool.node_empty();

  for (std::size_t i = 0; i < 0xFF; i++) {
    head = pool.allocate(static_cast<double>(i), head);
  }

  based::free_list(pool, head);

  auto queue = pool.queue_empty();
  for (std::size_t i = 0; i < 0xFF; i++) {
    if (i % 2 == 0) {
      queue = pool.push_front(queue, static_cast<double>(i));
    } else {
      queue = pool.push_back(queue, static_cast<double>(i));
    }

    if (i % 3 == 0) {
      queue = pool.pop_front(queue);
    }
  }

  pool.free(queue);

  return 0;
}
