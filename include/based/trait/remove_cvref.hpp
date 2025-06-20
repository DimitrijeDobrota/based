#pragma once

#include "based/trait/remove_reference.hpp"
#include "based/trait/remove_cv.hpp"

namespace based::trait
{

namespace detail
{

template<class T>
struct RemoveCvref
{
  using Type = trait::RemoveCv<trait::RemoveReference<T>>;
};

}  // namespace detail

template<class T>
using RemoveCvref = typename detail::RemoveCvref<T>::Type;

}  // namespace based::trait
