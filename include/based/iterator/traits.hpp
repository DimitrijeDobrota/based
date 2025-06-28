#pragma once

namespace based::trait
{

template<class Itr>
class Iterator;

template<class Itr>
using IterValue = typename trait::Iterator<Itr>::value_type;

template<class Itr>
using IterDifference = typename trait::Iterator<Itr>::difference_type;

template<class Itr>
using IterCategory = typename trait::Iterator<Itr>::iterator_category;

}  // namespace based::trait
