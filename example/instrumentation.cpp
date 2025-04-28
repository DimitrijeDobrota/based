#include <algorithm>
#include <iostream>

#include "based/instrumentation.hpp"

class reg : public based::registry<reg>
{
public:
  explicit reg(int val)
      : m_val(val)
  {
  }

  int m_val;
};

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
          std::sort(a, b);
        },
        based::normalize_nlogn
    );
  }

  {
    const based::timer time;

    based::count_operations(
        size,
        size * mega * mega,
        [](const auto& a, const auto& b)
        {
          std::stable_sort(a, b);
        },
        based::normalize_nlogn
    );
  }

  const reg a(0);
  const reg b(1);
  const reg c(2);

  std::cout << based::registry<reg>::count << '\n';
}
