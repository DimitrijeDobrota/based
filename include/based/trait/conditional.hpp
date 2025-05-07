#pragma once

namespace based
{

// clang-format off

template<bool b, class T, class F> struct conditional              { using type = T; };
template<class T, class F>         struct conditional<false, T, F> { using type = F; };

template<bool b, class T, class F> using conditional_t = conditional<b, T, F>::type;

// clang-format on

}  // namespace based
