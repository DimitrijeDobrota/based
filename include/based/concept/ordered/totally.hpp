#pragma once

#include "based/concept/comparable/equality.hpp"
#include "based/concept/comparable/greater.hpp"
#include "based/concept/comparable/greater_equal.hpp"
#include "based/concept/comparable/less.hpp"
#include "based/concept/comparable/less_equal.hpp"

namespace based::trait
{

template<class T>
concept TotallyOrdered = requires {
  requires(IsEqualityComparable<T>);
  requires(IsLessComparable<T>);
  requires(IsGreaterComparable<T>);
  requires(IsLessEqualComparable<T>);
  requires(IsGreaterEqualComparable<T>);
};

}  // namespace based::trait
