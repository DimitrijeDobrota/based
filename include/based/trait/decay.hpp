#pragma once

#include "based/trait/add_pointer.hpp"
#include "based/trait/is/array.hpp"
#include "based/trait/is/function.hpp"
#include "based/trait/remove_cv.hpp"
#include "based/trait/remove_extent.hpp"
#include "based/trait/remove_reference.hpp"

namespace based::trait
{

namespace detail
{

template<class U>
struct Decay
{
  using Type = trait::RemoveCv<U>;
};

template<class U>
  requires is_array_v<U>
struct Decay<U>
{
  using Type = trait::AddPointer<trait::RemoveExtent<U>>;
};

template<class U>
  requires is_function_v<U>
struct Decay<U>
{
  using Type = trait::AddPointer<U>;
};

}  // namespace detail

template<class T>
using Decay = typename detail::Decay<RemoveReference<T>>::Type;

}  // namespace based::trait
