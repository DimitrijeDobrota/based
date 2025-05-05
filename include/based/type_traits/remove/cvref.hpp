#pragma once

#include "based/type_traits/remove/cv.hpp"
#include "based/type_traits/remove/reference.hpp"

namespace based
{

// clang-format off

template<class T> struct remove_cvref {
    using type = remove_cv_t<remove_reference_t<T>>;
};

template<class T> using remove_cvref_t = typename remove_cvref<T>::type;

// clang-format on

}  // namespace based
