#pragma once

#include "based/concept/is_same.hpp"
#include "based/trait/remove_cv.hpp"

namespace based::trait
{

template<class T>
concept IsVoid = IsSame<void, trait::RemoveCv<T>>;

}  // namespace based::trait
