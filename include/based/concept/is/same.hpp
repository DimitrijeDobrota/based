#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove/cvref.hpp"

namespace based
{

template<class T, class U>
concept SameAs = is_same_v<T, U> && is_same_v<U, T>;

template<class T, class U>
concept BareSameAs = SameAs<remove_cvref_t<T>, remove_cvref_t<U>>;

}  // namespace based
