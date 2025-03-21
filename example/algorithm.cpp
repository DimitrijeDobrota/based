#include "based/algorithm.hpp"

#include "based/instrumentation.hpp"

int main()
{
  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
        [](const auto& a, const auto& b) { based::min_element(a, b); },
        based::normalize_n);
  }

  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
        [](const auto& a, const auto& b) { based::max_element(a, b); },
        based::normalize_n);
  }

  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
        [](const auto& a, const auto& b) { based::minmax_element(a, b); },
        based::normalize_n);
  }

  return 0;
}
