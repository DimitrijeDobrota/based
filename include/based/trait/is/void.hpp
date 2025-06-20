#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove_cv.hpp"

namespace based
{

template<class T>
struct IsVoid : IsSame<void, trait::RemoveCv<T>>
{
};

template<class T>
constexpr bool is_void_v = IsVoid<T>::value;

}  // namespace based
