#pragma once

#include "based/concept/is_array.hpp"
#include "based/concept/is_function.hpp"
#include "based/trait/add_pointer.hpp"
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
  requires trait::IsArray<U>
struct Decay<U>
{
  using Type = trait::AddPointer<trait::RemoveExtent<U>>;
};

template<class U>
  requires trait::IsFunction<U>
struct Decay<U>
{
  using Type = trait::AddPointer<U>;
};

}  // namespace detail

template<class T>
using Decay = typename detail::Decay<RemoveReference<T>>::Type;

}  // namespace based::trait
