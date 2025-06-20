#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = Regular<RemoveCvref<T>>;

}  // namespace based::trait
