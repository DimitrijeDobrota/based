#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

template<class T>
concept IsRegular = std::regular<T>;

template<class T>
concept IsRegularBare = IsRegular<RemoveCvref<T>>;

}  // namespace based::trait
