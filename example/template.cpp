#include <functional>
#include <iostream>

#include "based/functional/function.hpp"
#include "based/functional/overload.hpp"

int main()
{
  {
    const auto func = based::overload {
        [](const int* integer)
        {
          std::cout << "i=" << *integer << '\n';
        },
        [](const double* dbl)
        {
          std::cout << "d=" << *dbl << '\n';
        }
    };

    const int integer = 5;
    func(&integer);

    const double dbl = 7.3;
    func(&dbl);
  }

  {
    const based::function func = [](int val)
    {
      return val + 1;
    };
    std::cout << func(3) << '\n';
  }

  {
    const std::function func = [](int val)
    {
      return val + 1;
    };
    std::cout << func(3) << '\n';
  }

  return 0;
}
