#pragma once

namespace based
{

template<typename T>
auto not_null(const T* ptr)
{
  return ptr != nullptr;
}

}  // namespace based
