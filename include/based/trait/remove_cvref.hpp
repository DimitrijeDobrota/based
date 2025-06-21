#pragma once

#include "based/trait/remove_cv.hpp"
#include "based/trait/remove_reference.hpp"

namespace based::trait
{

namespace detail
{

template<class T>
struct RemoveCvrefHelper
{
  using Type = RemoveCv<RemoveReference<T>>;
};

}  // namespace detail

template<class T>
using RemoveCvref = typename detail::RemoveCvrefHelper<T>::Type;

}  // namespace based::trait
