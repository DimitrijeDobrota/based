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
  requires(EqualityComparable<T>);
  requires(LessComparable<T>);
  requires(GreaterComparable<T>);
  requires(LessEqualComparable<T>);
  requires(GreaterEqualComparable<T>);
};

}  // namespace based::trait
