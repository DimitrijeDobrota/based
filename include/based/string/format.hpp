#pragma once

#include <string>
#include <string_view>

namespace based
{

constexpr auto string_format(std::string_view format, auto... args)
{
  std::string_view::size_type last = 0;
  std::string res;

  [[maybe_unused]] const auto func = [&](std::string_view arg)
  {
    if (auto pos = format.find("{}", last); pos != std::string_view::npos) {
      res += format.substr(last, pos - last);
      res += arg;
      last = pos + 2;
    }
  };
  (func(args), ...);
  res += format.substr(last, std::size(format) - last);

  return res;
}

}  // namespace based
