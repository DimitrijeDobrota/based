#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove_cvref.hpp"

namespace based
{

template<class T, class U>
concept SameAs = is_same_v<T, U> && is_same_v<U, T>;

template<class T, class U>
concept BareSameAs = SameAs<trait::RemoveCvref<T>, trait::RemoveCvref<U>>;

}  // namespace based
