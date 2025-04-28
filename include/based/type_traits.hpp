#pragma once

#include <cstdint>
#include <iterator>
#include <tuple>
#include <type_traits>

#include "based/integer.hpp"

namespace based
{

/* ----- Integer ----- */

template<typename T>
concept Integer = requires(T n) {
  successor(n);
  predecessor(n);
  twice(n);
  half(n);
  positive(n);
  negative(n);
  zero(n);
  one(n);
  even(n);
  odd(n);
};

/* ----- Regular ----- */

template<typename T>
using bare_t = std::remove_cvref_t<T>;

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = std::regular<bare_t<T>>;

template<typename T, typename U>
concept SameAs = std::is_same_v<T, U> && std::is_same_v<U, T>;

template<typename T, typename U>
concept BareSameAs = SameAs<bare_t<T>, bare_t<U>>;

/* ----- Iterator ----- */

// clang-format off

namespace detail {
    template<typename I>
    struct iterator_traits {
        using value_type = I;
        using distance_type = std::uint64_t;
        using pointer_type = I&;
        using reference_type = I*;
    };

    template<typename I>
     requires   std::input_or_output_iterator<I>
    struct iterator_traits<I> {
        using value_type = std::iterator_traits<I>::value_type;
        using distance_type = std::iterator_traits<I>::difference_type;
        using pointer_type = std::iterator_traits<I>::pointer;
        using reference_type = std::iterator_traits<I>::reference;
    };


} // namespace detail


template<typename T>
using iter_value_t = detail::iterator_traits<T>::value_type;

template<typename T>
using iter_dist_t = detail::iterator_traits<T>::distance_type;

template<typename T>
using iter_ptr_t = detail::iterator_traits<T>::pointer;

template<typename T>
using iter_ref_t = detail::iterator_traits<T>::reference;

template<typename T>
concept Readable = requires(T t) {
  requires(Regular<T>);
  typename iter_value_t<T>;
  { *t } -> BareSameAs<iter_value_t<T>>;
};

template<typename T>
concept Iterator = requires(T t) {
    requires(Regular<T>);
    typename iter_dist_t<T>;
    // requires(Integer<iter_dist_t<T>>);
    { ++t } -> BareSameAs<T>;
    // successor is not necessarily regular

};

template<typename T>
concept ForwardIterator = requires(T t) {
    requires(Iterator<T>);
    // successor is regular
};

template<typename T>
concept ReadableIterator = requires {
    requires(Iterator<T>);
    requires(Readable<T>);
};

template<typename T>
concept ReadableForwardIterator = requires {
    requires(ForwardIterator<T>);
    requires(Readable<T>);
};

// clang-format on

template<typename T>
concept Input = std::is_same_v<T, std::remove_cvref_t<std::remove_pointer_t<T>>>
    || std::is_const_v<std::remove_reference_t<T>>
    || std::is_const_v<std::remove_pointer_t<T>>;

namespace detail
{

template<typename... Args>
struct is_homogeneous_domain : std::false_type
{
};

template<typename Head, typename... Args>
  requires(std::same_as<Head, Args> && ...)
struct is_homogeneous_domain<Head, Args...> : std::true_type
{
};

}  // namespace detail

template<typename... Args>
concept RegularDomain =
    requires { requires(Regular<std::remove_cvref_t<Args>> && ...); };

template<typename... Args>
concept InputDomain = requires { requires(Input<Args> && ...); };

template<typename... Args>
concept HomogenousDomain = detail::is_homogeneous_domain<Args...>::value;

template<typename T>
using distance_t = std::uint64_t;

template<typename P, typename... Args>
concept Procedure = std::invocable<P, Args...>;

template<typename P, typename... Args>
  requires Procedure<P, Args...>
inline constexpr auto arity_v = std::tuple_size<std::tuple<Args...>>::value;

template<typename P, std::size_t idx, typename... Args>
  requires Procedure<P, Args...> && requires { idx < arity_v<Args...>; }
using domain_elem_t =
    std::decay_t<std::tuple_element_t<idx, std::tuple<Args...>>>;

template<typename P, typename... Args>
  requires Procedure<P, Args...>
using codomain_t = std::invoke_result_t<P, Args...>;

template<typename P, typename Arg>
concept UnaryProcedure = requires {
  requires(Procedure<P, Arg>);
  requires(arity_v<P, Arg> == 1);
};

template<typename P, typename... Args>
concept RegularProcedure = requires {
  requires(Procedure<P, Args...>);
  requires(RegularDomain<Args...>);
  requires(Regular<codomain_t<P, Args...>>);
};

template<typename P, typename... Args>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P, Args...>);
  requires(InputDomain<Args...>);
};

template<typename P, typename Arg>
concept UnaryFunction = requires {
  requires(FunctionalProcedure<P, Arg>);
  requires(UnaryProcedure<P, Arg>);
};

template<typename P, typename... Args>
concept HomogeneousFunction = requires {
  requires(FunctionalProcedure<P, Args...>);
  requires(arity_v<P, Args...> > 0);
  requires(HomogenousDomain<Args...>);
};

template<typename P, typename... Args>
concept Predicate = requires {
  requires(FunctionalProcedure<P, Args...>);
  requires(std::same_as<bool, codomain_t<P, Args...>>);
};

template<typename P, typename... Args>
concept HomogeneousPredicate = requires {
  requires(Predicate<P, Args...>);
  requires(HomogeneousFunction<P, Args...>);
};

template<typename P, typename Arg>
concept UnaryPredicate = requires {
  requires(Predicate<P, Arg>);
  requires(UnaryFunction<P, Arg>);
};

template<typename P, typename... Args>
concept Operation = requires {
  requires(HomogeneousFunction<P, Args...>);
  requires(BareSameAs<
           codomain_t<P, Args...>,
           std::tuple_element_t<0, std::tuple<Args...>>>);
};

template<typename P, typename Arg>
concept Transformation = requires {
  requires(Operation<P, Arg>);
  requires(UnaryFunction<P, Arg>);
};

template<typename P, typename Arg>
concept BinaryOperation = requires {
  requires(Operation<P, Arg, Arg>);
  requires(arity_v<P, Arg, Arg> == 2);
};

template<typename P, typename Arg>
concept AssociativeBinaryOperation = requires {
  requires(Operation<P, Arg, Arg>);
  requires(arity_v<P, Arg, Arg> == 2);
};

template<typename P, typename Arg>
concept Relation = requires {
  requires(HomogeneousPredicate<P, Arg, Arg>);
  requires(arity_v<P, Arg, Arg> == 2);
};

/* ----- Iterator variants ----- */

template<typename P, typename I>
concept IterUnaryProcedure = requires {
  requires(Iterator<I>);
  requires(UnaryProcedure<P, iter_value_t<I>>);
};

template<typename P, typename I>
concept IterUnaryFunction = requires {
  requires(Iterator<I>);
  requires(UnaryFunction<P, iter_value_t<I>>);
};

template<typename P, typename... I>
concept IterHomogeneousPredicate = requires {
  requires(Iterator<I> && ...);
  requires(HomogeneousPredicate<P, iter_value_t<I>...>);
};

template<typename P, typename I>
concept IterUnaryPredicate = requires {
  requires(Iterator<I>);
  requires(UnaryPredicate<P, iter_value_t<I>>);
};

template<typename P, typename... I>
concept IterOperation = requires {
  requires(Iterator<I> && ...);
  requires(Operation<P, iter_value_t<I>...>);
};

template<typename P, typename I>
concept IterBinaryOperation = requires {
  requires(Iterator<I>);
  requires(BinaryOperation<P, iter_value_t<I>>);
};

template<typename P, typename I>
concept IterRelation = requires {
  requires(Iterator<I>);
  requires(Relation<P, iter_value_t<I>>);
};

/* ----- Abstract Algebra ----- */

// clang-format off
template<typename T>
concept AdditiveSemigroup = requires(T a, T b) {
  requires(Regular<T>);
  { a + b } -> std::same_as<T>;
  // associative(+)
  // commutative(+)
};

template<typename T>
concept MultiplicativeSemigroup = requires(T a, T b) {
  requires(Regular<T>);
  { a * b } -> std::same_as<T>;
  // associative(*)
};

template<typename T>
concept AdditiveMonoid = requires {
  requires(AdditiveSemigroup<T>);
  requires(T{0});
  // identity_element(0, +);
};

template<typename T>
concept MultiplicativeMonoid = requires {
  requires(MultiplicativeSemigroup<T>);
  requires(T{1});
  // identity_element(1, *);
};

template<typename T>
concept AdditiveGroup = requires(T a, T b) {
  requires(AdditiveMonoid<T>);
  { -a } -> std::same_as<T>;
  // inverse_operation(unary -, 0, +);
  { a - b } -> std::same_as<T>;
};

template<typename T>
concept MultiplicativeGroup = requires(T a, T b) {
  requires(MultiplicativeMonoid<T>);
  // multiplicative_inverse: T -> T;
  // inverse_operation(multiplicative_inverse, 1, *)
  { a / b } -> std::same_as<T>;
};

template<typename T>
concept Semiring = requires {
  requires(AdditiveMonoid<T>);
  requires(MultiplicativeMonoid<T>);
  requires(T{0} != T{1});
  // annihilation property of 0
  // distributivity of multiplication over addition
};

template<typename T>
concept CommutativeSemiring = requires {
  requires(Semiring<T>);
  // commutative(*)
};

template<typename T>
concept Ring = requires {
  requires(AdditiveGroup<T>);
  requires(Semiring<T>);
};

template<typename T>
concept CommutativeRing = requires {
  requires(AdditiveGroup<T>);
  requires(CommutativeSemiring<T>);
};

template<typename T, typename S>
// T -> vectors; S -> scalars
concept Semimodule = requires (S s, T t) {
  requires(AdditiveGroup<T>);
  requires(CommutativeSemiring<S>);
  { s * t } -> std::same_as<T>;
};

template<typename T, typename S>
// T -> vectors; S -> scalars
concept Module = requires {
  requires(Semimodule<T, S>);
  requires(AdditiveGroup<T>);
  requires(Ring<S>);
};

// clang-format on

}  // namespace based
