#pragma once

#include "based/trait/remove/cv.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

// clang-format off

template<class T> struct RemoveCvref {
    using Type = RemoveCvT<RemoveReferenceT<T>>;
};

template<class T> using RemoveCvrefT = typename RemoveCvref<T>::Type;

// clang-format on

}  // namespace based
