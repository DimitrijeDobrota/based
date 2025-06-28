#pragma once

#include "based/concept/comparable/equality.hpp"
#include "based/concept/is_copy_assignable.hpp"
#include "based/concept/is_copy_constructible.hpp"
#include "based/concept/is_destructible.hpp"
#include "based/concept/is_referenceable.hpp"
#include "based/concept/is_same.hpp"
#include "based/concept/is_swappable.hpp"
#include "based/iterator/traits.hpp"

namespace based::trait
{

template<class Itr>
concept IsLegacyIterator = requires(Itr itr) {
  requires(IsCopyConstructible<Itr>);
  requires(IsCopyAssignable<Itr>);
  requires(IsDestructible<Itr>);
  requires(IsSwappable<Itr>);
  typename trait::Iterator<Itr>::difference_type;
  typename trait::Iterator<Itr>::reference;
  typename trait::Iterator<Itr>::pointer;
  typename trait::Iterator<Itr>::iterator_category;
  // clang-format off
  {   *itr } -> IsReferenceable;
  {  ++itr } -> IsSame<Itr&>;
  { *itr++ } -> IsReferenceable;
  // clang-format on
};

template<class Itr>
concept IsLegacyInputIterator = requires(Itr itr) {
  requires(IsLegacyIterator<Itr>);
  requires(IsEqualityComparable<Itr>);
};

}  // namespace based::trait
