#pragma once

namespace based
{

template<typename T>
T successor(T n)
{
  return n + T {1};
}

template<typename T>
T predecesor(T n)
{
  return n - T {1};
}

template<typename T>
T twice(T n)
{
  return n * T {2};
}

template<typename T>
T half(T n)
{
  return n / T {2};
}

template<typename T>
bool positive(T n)
{
  return n > T {0};
}

template<typename T>
bool negative(T n)
{
  return n < T {0};
}

template<typename T>
bool zero(T n)
{
  return n == T {0};
}

template<typename T>
bool one(T n)
{
  return n == T {1};
}

template<typename T>
bool two(T n)
{
  return n == T {2};
}

template<typename T>
bool even(T n)
{
  return n % T{2} == T{0};
}

template<typename T>
bool odd(T n)
{
  return n % T{2} != T{0};
}

}  // namespace based
