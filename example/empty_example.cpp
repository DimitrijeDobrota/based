#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

#include "based/instrumentation.hpp"

int main()
{
  using instrumented = based::instrumented<int>;

  std::vector<int> base = {12, 5, 52, 5, 62, 46, 53, 73, 8, 83, 6};
  std::vector<instrumented> vec(std::begin(base), std::end(base));

  instrumented::initialize(vec.size());
  std::sort(std::begin(vec), std::end(vec));

  for (std::size_t i = 0; i < instrumented::size(); i++) {
    std::cout << std::format(
        "{:15}: {}\n", instrumented::name(i), instrumented::count(i));
  }

  return 0;
}
