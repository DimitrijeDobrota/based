#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based
{

template<typename T>
concept Semiregular = std::semiregular<T>;

template<typename T>
concept BareSemiregular = Semiregular<trait::RemoveCvref<T>>;

}  // namespace based
