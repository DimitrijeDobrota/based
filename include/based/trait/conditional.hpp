#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<bool b, class T, class F> struct Conditional              { using Type = T; };
template<class T, class F>         struct Conditional<false, T, F> { using Type = F; };
// clang-format on

}  // namespace detail

template<bool b, class T, class F>
using Conditional = typename detail::Conditional<b, T, F>::Type;

}  // namespace based::trait
