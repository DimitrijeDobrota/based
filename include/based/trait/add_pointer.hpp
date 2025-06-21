#pragma once

#include "based/trait/remove_reference.hpp"
#include "based/trait/type_identity.hpp"

namespace based::trait
{

namespace detail
{

template<class T>
auto try_add_pointer(int) -> TypeIdentity<RemoveReference<T>*>;

template<class T>
auto try_add_pointer(...) -> TypeIdentity<T>;

template<class T>
struct AddPointerHelper : decltype(detail::try_add_pointer<T>(0))
{
};

}  // namespace detail

template<class T>
using AddPointer = typename detail::AddPointerHelper<T>::Type;

}  // namespace based::trait
