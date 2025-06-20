#pragma once

#include <concepts>

#include "based/trait/remove/cvref.hpp"

namespace based
{

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = Regular<RemoveCvrefT<T>>;

}  // namespace based
