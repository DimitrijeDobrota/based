#include <cstdint>

#include "based/list.hpp"

#include "based/instrumentation.hpp"

int main()
{
  using instrumented = based::instrumented<double>;

  based::list_pool<instrumented, std::uint8_t> pool;
  auto head = pool.empty();

  for (std::size_t i = 0; i < 0xFF; i++) {
    head = pool.allocate(static_cast<double>(i), head);
  }

  based::free_list(pool, head);

  return 0;
}
