#pragma once

#include <format>
#include <iostream>

#include "based/integral/types.hpp"

namespace based
{

class Table
{
public:
  explicit Table(SizeT min_wth)
      : m_min_wth(min_wth)
  {
  }

  template<typename I>
  void print_header(I first, I last)
  {
    while (first != last) {
      std::cout << std::format("{:^{}} | ", *first, m_min_wth);
      first++;
    }
    std::cout << '\n';
  }

  template<typename I>
  void print_row(I first, I last, SizeT precision)
  {
    std::cout << std::format("{:{}} | ", *first++, m_min_wth);
    while (first != last) {
      std::cout << std::format("{:{}.{}f} | ", *first, m_min_wth, precision);
      first++;
    }
    std::cout << '\n';
  }

private:
  SizeT m_min_wth;
};

}  // namespace based
