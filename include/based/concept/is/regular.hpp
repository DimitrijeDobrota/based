#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based
{

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = Regular<trait::RemoveCvref<T>>;

}  // namespace based
