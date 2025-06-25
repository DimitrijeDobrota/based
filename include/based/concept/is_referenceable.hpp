#pragma once

#include "based/concept/is_same.hpp"

namespace based::trait
{

template<class T>
concept IsReferenceable = !IsSame<void, T>;

}  // namespace based::trait
