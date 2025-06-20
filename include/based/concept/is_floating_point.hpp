#pragma once

#include "based/concept/is_same.hpp"
#include "based/trait/remove_cv.hpp"

namespace based::trait
{

template<class T>
concept IsFloatingPoint =
    IsSame<float, trait::RemoveCv<T>> || IsSame<double, trait::RemoveCv<T>>
    || IsSame<long double, trait::RemoveCv<T>>;

}  // namespace based::trait
