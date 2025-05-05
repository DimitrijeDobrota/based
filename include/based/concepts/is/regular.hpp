#pragma once

#include <concepts>

#include "based/type_traits/remove/cvref.hpp"

namespace based
{

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = Regular<remove_cvref_t<T>>;

}  // namespace based
