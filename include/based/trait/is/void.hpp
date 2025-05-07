#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"

namespace based
{

template<class T>
struct is_void : is_same<void, remove_cv_t<T>>
{
};

template<class T>
constexpr bool is_void_v = is_void<T>::value;

}  // namespace based
