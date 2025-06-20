#pragma once

namespace based
{

// clang-format off

template<bool b, class T, class F> struct Conditional              { using type = T; };
template<class T, class F>         struct Conditional<false, T, F> { using type = F; };

template<bool b, class T, class F> using conditional_t = Conditional<b, T, F>::type;

// clang-format on

}  // namespace based
