#pragma once

#include "based/concept/is_same.hpp"
#include "based/memory/nullptr.hpp"
#include "based/trait/remove_cv.hpp"

namespace based::trait
{

template<class T>
concept IsNullPointer = IsSame<NullptrT, RemoveCv<T>>;

}  // namespace based::trait
