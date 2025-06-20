#pragma once

namespace based::trait
{

namespace detail
{

template<class T>
struct RemoveConst
{
  using Type = T;
};

template<class T>
struct RemoveConst<const T>
{
  using Type = T;
};

}  // namespace detail

template<class T>
using RemoveConst = typename detail::RemoveConst<T>::Type;

}  // namespace based::trait
