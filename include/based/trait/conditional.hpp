#pragma once

namespace based::trait
{

namespace detail
{

// clang-format off
template<bool b, class T, class F> struct ConditionalHelper              { using Type = T; };
template<class T, class F>         struct ConditionalHelper<false, T, F> { using Type = F; };
// clang-format on

}  // namespace detail

template<bool b, class T, class F>
using Conditional = typename detail::ConditionalHelper<b, T, F>::Type;

}  // namespace based::trait
