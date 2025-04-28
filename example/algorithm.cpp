#include "based/algorithm.hpp"

#include "based/instrumentation.hpp"

int main()
{
  static constexpr std::size_t size = 16;
  static constexpr std::size_t mega = 1024;

  {
    const based::timer time;

    based::count_operations(
        size,
        size * mega * mega,
        [](const auto& a, const auto& b)
        {
          based::min_element(a, b);
        },
        based::normalize_n
    );
  }

  {
    const based::timer time;

    based::count_operations(
        size,
        size * mega * mega,
        [](const auto& a, const auto& b)
        {
          based::max_element(a, b);
        },
        based::normalize_n
    );
  }

  {
    const based::timer time;

    based::count_operations(
        size,
        size * mega * mega,
        [](const auto& a, const auto& b)
        {
          based::minmax_element(a, b);
        },
        based::normalize_n
    );
  }

  return 0;
}
