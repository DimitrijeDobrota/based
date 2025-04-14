#include <iostream>

#include "based/template.hpp"

int main()
{
  const auto l =
      based::overload([](const int* i) { std::cout << "i=" << *i << '\n'; },
                      [](const double* d) { std::cout << "d=" << *d << '\n'; });

  int i = 5;
  l(&i);

  double d = 7.3;
  l(&d);

  return 0;
}
