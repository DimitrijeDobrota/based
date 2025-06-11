#pragma once

namespace based
{

template<auto data>
inline constexpr const auto& make_static = data;

}  // namespace based
