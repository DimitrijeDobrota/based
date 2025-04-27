#include <algorithm>
#include <iostream>

#include "based/instrumentation.hpp"

class reg : public based::registry<reg>
{
public:
  explicit reg(int i)
      : m_i(i)
  {
  }

  int m_i;
};

int main()
{
  {
    const based::timer time;

    based::count_operations(
        16UL,
        16UL * 1024 * 1024,
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
        16UL,
        16UL * 1024 * 1024,
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
