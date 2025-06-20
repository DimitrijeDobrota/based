#pragma once

#include <concepts>

#include "based/trait/remove/cvref.hpp"

namespace based
{

template<typename T>
concept Semiregular = std::semiregular<T>;

template<typename T>
concept BareSemiregular = Semiregular<RemoveCvrefT<T>>;

}  // namespace based
