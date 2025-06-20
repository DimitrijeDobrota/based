#pragma once

#include "based/memory/nullptr.hpp"
#include "based/trait/is/same.hpp"
#include "based/trait/remove_cv.hpp"

namespace based
{

template<class T>
struct IsNullPointer : IsSame<NullptrT, trait::RemoveCv<T>>
{
};

template<class T>
constexpr bool is_null_pointer_v = IsNullPointer<T>::value;

}  // namespace based
