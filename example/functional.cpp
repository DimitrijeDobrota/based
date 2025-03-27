#include <iostream>

#include "based/functional.hpp"

int main()
{
  static const auto func = [](int x) { return x != 32 ? 2 * x : 1; };
  static const auto pred = [](int /* x */) { return true; };

  std::cout << based::distance(1, 16, func) << '\n';
  std::cout << based::power_unary(1, 2, func) << '\n';

  std::cout << '\n';
  std::cout << based::collision_point(1, func, pred) << '\n';
  std::cout << based::terminating(1, func, pred) << '\n';
  std::cout << based::circular(1, func, pred) << '\n';
  std::cout << based::connection_point(1, func, pred) << '\n';

  std::cout << '\n';
  std::cout << based::collision_point_nonterminating_orbit(1, func) << '\n';
  std::cout << based::circular_nonterminating_orbit(1, func) << '\n';
  std::cout << based::connection_point_nonterminating_orbit(1, func) << '\n';

  return 0;
}
