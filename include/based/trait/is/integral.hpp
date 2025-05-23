#pragma once

#include "based/trait/integral_constant.hpp"

namespace based
{

template<class T>
struct is_integral : false_type
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
struct is_integral<T> : true_type
{
};

template<class T>
constexpr bool is_integral_v = is_integral<T>::value;

}  // namespace based
