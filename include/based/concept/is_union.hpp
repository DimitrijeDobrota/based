#pragma once

#include <type_traits>

namespace based::trait
{

template<class T>
concept IsUnion = std::is_union_v<T>;

}  // namespace based::trait
