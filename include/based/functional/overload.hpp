#pragma once

namespace based
{

/* ----- Overload Lambdas ----- */

template<typename... F>
struct Overload : public F...
{
  using F::operator()...;
};

template<typename... F>
Overload(F&&...) -> Overload<F...>;

}  // namespace based
