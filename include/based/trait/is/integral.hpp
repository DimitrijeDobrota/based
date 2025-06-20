#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct IsIntegral : FalseType
{
};

template<class T>
  requires(
      requires(
          T obj, T* ptr, void (*func)(T)
      )  // T* parameter excludes reference types
      {
        reinterpret_cast<T>(obj);  // NOLINT(*reinterpret*, *redundant*)
        func(0);  // Exclude enumeration types
        ptr + obj;  // Exclude everything not yet excluded but integral types
      }
  )
struct IsIntegral<T> : TrueType
{
};

template<class T>
constexpr bool is_integral_v = IsIntegral<T>::value;

}  // namespace based
