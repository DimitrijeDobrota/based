#pragma once

#include <concepts>

#include "based/trait/remove_cvref.hpp"

namespace based::trait
{

template<class T>
concept IsSemiregular = std::semiregular<T>;

template<class T>
concept IsSemiregularBare = IsSemiregular<RemoveCvref<T>>;

}  // namespace based::trait
