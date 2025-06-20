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
  using u = remove_reference_t<T>;

public:
  using type = conditional_t<
      is_array_v<u>,
      add_pointer_t<remove_extent_t<u>>,
      conditional_t<
		is_function_v<u>,
		add_pointer_t<u>,
		remove_cv_t<u>>
	  >;
};

template<class T> using decay_t = typename Decay<T>::type;

// clang-format on

}  // namespace based
