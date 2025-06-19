#pragma once

#include <concepts>

#include "based/trait/remove/cvref.hpp"

namespace based
{

template<typename T>
concept Semiregular = std::semiregular<T>;

template<typename T>
concept BareSemiregular = Semiregular<remove_cvref_t<T>>;

}  // namespace based
