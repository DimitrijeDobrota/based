#pragma once

#include "based/trait/remove/cv.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

// clang-format off

template<class T> struct RemoveCvref {
    using type = remove_cv_t<remove_reference_t<T>>;
};

template<class T> using remove_cvref_t = typename RemoveCvref<T>::type;

// clang-format on

}  // namespace based
