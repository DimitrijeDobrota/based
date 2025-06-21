#pragma once

namespace based::trait
{

template<class T>
struct TypeIdentity
{
  using Type = T;
};

}  // namespace based::trait
