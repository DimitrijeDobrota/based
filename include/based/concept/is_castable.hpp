#pragma once

#include "based/utility/declvar.hpp"

namespace based::trait
{

template<class From, class To>
concept IsCastableTo = requires { static_cast<To>(declval<From>()); };

}  // namespace based::trait
