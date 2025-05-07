#pragma once

#include "based/trait/is/same.hpp"
#include "based/trait/remove/cv.hpp"
#include "based/types/nullptr.hpp"

namespace based
{

template<class T>
struct is_null_pointer : is_same<nullptr_t, remove_cv_t<T>>
{
};

template<class T>
constexpr bool is_null_pointer_v = is_null_pointer<T>::value;

}  // namespace based
