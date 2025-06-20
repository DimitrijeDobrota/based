#pragma once

#include "based/concept/is_convertible.hpp"
#include "based/integral/types.hpp"

namespace based::trait
{

template<class T>
concept IsSignedIntegral = IsConvertible<I, T>;

template<class T>
concept IsUnsignedIntegral = IsConvertible<U, T>;

template<class T>
concept IsIntegral = IsSignedIntegral<T> || IsUnsignedIntegral<T>;

}  // namespace based::trait
