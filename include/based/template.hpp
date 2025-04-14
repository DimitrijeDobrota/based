#pragma once

namespace based
{

template<typename... F>
struct overload : public F...
{
  using F::operator()...;
};

template<typename... F>
overload(F&&...) -> overload<F...>;

}  // namespace based
