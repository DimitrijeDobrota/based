#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

template<class T>
struct IsVoid : IsSame<void, RemoveCvT<T>>
{
};

template<class T>
constexpr bool is_void_v = IsVoid<T>::value;

}  // namespace based
