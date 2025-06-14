#pragma once

#include <algorithm>
#include <string>

namespace based
{

template<class T>
// requires unsigned integral types
constexpr std::string to_string(T value)
{
  constexpr const T radix = 10;
  std::string res;

  do {
    res.push_back('0' + (value % radix));
  } while ((value /= radix) > 0);

  std::ranges::reverse(res);

  return res;
}

}  // namespace based
