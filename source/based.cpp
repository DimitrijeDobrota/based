#include <format>
#include <string>

#include "based/based.hpp"

exported_class::exported_class()
    : m_name {std::format("{}", "based")}
{
}

auto exported_class::name() const -> char const*
{
  return m_name.c_str();
}
