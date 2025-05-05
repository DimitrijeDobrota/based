#include <cstdint>

#include "based/list.hpp"

#include "based/instrumentation.hpp"

based::instrumented_base::op::type::array<double>
    based::instrumented_base::counts;

int main()
{
  using instrumented = based::instrumented<double>;
  using list_pool = based::list_pool<instrumented, std::uint8_t>;
  using iter = list_pool::iterator;

  static constexpr std::size_t iter_count = 0xFF;

  auto pool = list_pool();
  auto head = pool.node_empty();

  for (std::size_t i = 0; i < iter_count; i++) {
    head = pool.allocate(static_cast<double>(i), head);
  }

  for (auto it = iter(pool, head); it != iter(pool); ++it) {
    std::cout << *it << " ";
  }
  std::cout << '\n';

  based::free_list(pool, head);

  auto queue = pool.queue_empty();
  for (std::size_t i = 0; i < iter_count; i++) {
    if (i % 2 == 0) {
      queue = pool.push_front(queue, static_cast<double>(i));
    } else {
      queue = pool.push_back(queue, static_cast<double>(i));
    }

    if (i % 3 == 0) {
      queue = pool.pop_front(queue);
    }
  }

  for (auto it = iter(pool, queue.first); it != iter(pool); ++it) {
    std::cout << *it << " ";
  }
  std::cout << '\n';

  pool.free(queue);

  return 0;
}
