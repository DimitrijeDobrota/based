#pragma once

#include "based/trait/remove_reference.hpp"
#include "based/trait/type_identity.hpp"

namespace based::trait
{

namespace detail
{

template<class T>
auto try_add_pointer(int) -> TypeIdentity<trait::RemoveReference<T>*>;

template<class T>
auto try_add_pointer(...) -> TypeIdentity<T>;

template<class T>
struct AddPointer : decltype(detail::try_add_pointer<T>(0))
{
};

}  // namespace detail

template<class T>
using AddPointer = typename detail::AddPointer<T>::Type;

}  // namespace based::trait
