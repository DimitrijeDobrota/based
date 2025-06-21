#pragma once

namespace based::trait
{

namespace detail
{

template<class T>
struct RemoveConstHelper
{
  using Type = T;
};

template<class T>
struct RemoveConstHelper<const T>
{
  using Type = T;
};

}  // namespace detail

template<class T>
using RemoveConst = typename detail::RemoveConstHelper<T>::Type;

}  // namespace based::trait
