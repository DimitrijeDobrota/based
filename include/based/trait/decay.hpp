#pragma once

#include "based/trait/add/pointer.hpp"
#include "based/trait/conditional.hpp"
#include "based/trait/is/array.hpp"
#include "based/trait/is/function.hpp"
#include "based/trait/remove/cv.hpp"
#include "based/trait/remove/extent.hpp"
#include "based/trait/remove/reference.hpp"

namespace based
{

// clang-format off

template<class T>
struct Decay
{
private:
  using U = RemoveReferenceT<T>;

public:
  using Type = ConditionalT<
      is_array_v<U>,
      AddPointerT<RemoveExtentT<U>>,
      ConditionalT<
		is_function_v<U>,
		AddPointerT<U>,
		RemoveCvT<U>>
	  >;
};

template<class T> using DecayT = typename Decay<T>::Type;

// clang-format on

}  // namespace based
