#pragma once

#include "based/utility/declvar.hpp"

namespace based
{

template<class From, class To>
concept CastableTo = requires { static_cast<To>(declval<From>()); };

}  // namespace based
