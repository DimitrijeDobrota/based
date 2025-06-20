#pragma once

namespace based
{

// clang-format off

template<bool b, class T, class F> struct Conditional              { using Type = T; };
template<class T, class F>         struct Conditional<false, T, F> { using Type = F; };

template<bool b, class T, class F> using ConditionalT = Conditional<b, T, F>::Type;

// clang-format on

}  // namespace based
