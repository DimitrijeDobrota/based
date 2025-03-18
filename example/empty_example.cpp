#include <algorithm>

#include "based/instrumentation.hpp"

int main()
{
  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
        [](const auto& a, const auto& b) { std::sort(a, b); },
        based::normalize_nlogn);
  }

  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
        [](const auto& a, const auto& b) { std::stable_sort(a, b); },
        based::normalize_nlogn);
  }

  return 0;
}
