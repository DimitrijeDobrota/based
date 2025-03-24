#include "based/type_traits.hpp"

struct irregular
{
  irregular() = default;

  irregular(const irregular&) = delete;
  irregular(irregular&&) = delete;

  irregular& operator=(const irregular&) = delete;
  irregular& operator=(irregular&&) = delete;

  ~irregular() = default;
};

template<typename T>
struct identity
{
  using input_types = std::tuple<T>;
  using output_type = T;

  output_type operator()(T val) { return val; }
};

struct identity_wrong_input_tuple
{
  using input_types = int;  // should be a tuple
  using output_type = int;

  output_type operator()(int val) { return val; }
};

struct identity_wrong_input_tuple_irregular
{
  using input_types = std::tuple<irregular>;  // should be a regular tuple
  using output_type = int;

  output_type operator()(irregular /* val */) { return 1; }
};

int main()
{
  static_assert(std::same_as<based::domain_t<identity<int>>, std::tuple<int>>);
  static_assert(based::arity_v<identity<int>> == 1);

  static_assert(based::Procedure<identity<int>>);
  static_assert(based::Procedure<identity<irregular>>);

  static_assert(!based::Procedure<identity_wrong_input_tuple>);

  static_assert(based::RegularProcedure<identity<int>>);
  static_assert(!based::RegularProcedure<identity<irregular>>);

  static_assert(!based::RegularProcedure<identity_wrong_input_tuple_irregular>);
}
