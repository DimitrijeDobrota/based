#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

template<typename T>
concept Semiregular = std::semiregular<T>;

template<typename T>
concept BareSemiregular = Semiregular<RemoveCvref<T>>;

}  // namespace based::trait
