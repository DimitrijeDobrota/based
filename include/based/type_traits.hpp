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
  typename T::value_type;
  { *t } -> std::same_as<typename T::value_type>;
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
concept ReadableIterator = requires {
    requires(Iterator<T>);
    requires(Readable<T>);
};

// clang-format on

template<typename T>
concept Input =
    std::is_same_v<T,
                   std::remove_volatile_t<
                       std::remove_reference_t<std::remove_pointer_t<T>>>>
    || (std::is_lvalue_reference_v<T>
        && std::is_const_v<std::remove_reference_t<T>>);

namespace detail
{

template<typename Fun>
concept FreeProcedure = std::is_function_v<std::remove_pointer_t<Fun>>;

template<typename Fun>
concept MemberProcedure = std::is_member_function_pointer_v<std::decay_t<Fun>>;

template<typename Fun>
concept FunctorProcedure = std::is_class_v<std::decay_t<Fun>>
    && requires(Fun&& t) { &std::decay_t<Fun>::operator(); };

template<class>
struct is_regular_tuple : std::false_type
{
};

template<template<class...> class Tuple, class... Types>
  requires(Regular<std::remove_cvref_t<Types>> && ...)
struct is_regular_tuple<Tuple<Types...>> : std::true_type
{
};

template<class T>
inline constexpr bool is_regular_tuple_v = is_regular_tuple<T>::value;

template<class>
struct is_input_tuple : std::false_type
{
};

template<template<class...> class Tuple, class... Types>
  requires(Input<Types> && ...)
struct is_input_tuple<Tuple<Types...>> : std::true_type
{
};

template<class T>
inline constexpr bool is_input_tuple_v = is_input_tuple<T>::value;

template<class>
struct is_homogenous_tuple : std::false_type
{
};

template<template<class...> class Tuple, typename Head, typename... Tail>
  requires(std::same_as<Head, Tail> && ...)
struct is_homogenous_tuple<Tuple<Head, Tail...>> : std::true_type
{
};

template<class T>
inline constexpr bool is_homogenous_tuple_v = is_homogenous_tuple<T>::value;

template<typename>
struct signature;

template<typename Ret, typename... Args>
struct signature<Ret(Args...)>
{
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_value = std::false_type;
  using volataile_value = std::false_type;
};

template<typename Ret, typename Obj, typename... Args>
struct signature<Ret (Obj::*)(Args...)>
{
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_value = std::false_type;
  using volataile_value = std::false_type;
};

template<typename Ret, typename Obj, typename... Args>
struct signature<Ret (Obj::*)(Args...) const>
{
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_value = std::true_type;
  using volataile_value = std::false_type;
};

template<typename Ret, typename Obj, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile>
{
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_value = std::false_type;
  using volataile_value = std::true_type;
};

template<typename Ret, typename Obj, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile>
{
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_value = std::true_type;
  using volataile_value = std::true_type;
};

template<typename>
struct domain;

template<FreeProcedure P>
struct domain<P>
{
  using type = signature<std::remove_pointer_t<P>>::arg_type;
};

template<FunctorProcedure P>
struct domain<P>
{
  using type = signature<decltype(&std::decay_t<P>::operator())>::arg_type;
};

template<MemberProcedure P>
struct domain<P>
{
  using type = signature<std::decay_t<P>>::arg_type;
};

template<typename>
struct codomain;

template<FreeProcedure P>
struct codomain<P>
{
  using type = signature<std::remove_pointer_t<P>>::ret_type;
};

template<FunctorProcedure P>
struct codomain<P>
{
  using type = signature<decltype(&std::decay_t<P>::operator())>::ret_type;
};

template<MemberProcedure P>
struct codomain<P>
{
  using type = signature<std::decay_t<P>>::ret_type;
};

template<typename P>
using domain_t = domain<P>::type;

template<typename P>
using codomain_t = codomain<P>::type;

template<class T>
concept RegularDomain = is_regular_tuple_v<domain_t<T>>;

template<class T>
concept InputDomain = is_input_tuple_v<domain_t<T>>;

template<class T>
concept HomogenousDomain = is_input_tuple_v<domain_t<T>>;

}  // namespace detail

template<typename P>
inline constexpr auto arity_v = std::tuple_size<detail::domain_t<P>>::value;

template<typename P, std::size_t Idx>
  requires requires { Idx < arity_v<P>; }
using domain_elem_t =
    std::decay_t<std::tuple_element_t<Idx, detail::domain_t<P>>>;

template<typename P>
using domain_t =
    std::conditional_t<detail::is_homogenous_tuple_v<detail::domain_t<P>>,
                       domain_elem_t<P, 0>,
                       detail::domain_t<P>>;

template<typename P>
using codomain_t = detail::codomain_t<P>;

template<typename T>
using distance_t = std::uint64_t;

template<typename P>
concept Procedure = detail::FreeProcedure<P> || detail::MemberProcedure<P>
    || detail::FunctorProcedure<P>;

template<typename P>
concept UnaryProcedure = requires {
  requires(Procedure<P>);
  requires(arity_v<P> == 1);
};

template<typename P>
concept RegularProcedure = requires {
  requires(Procedure<P>);
  requires(detail::RegularDomain<P>);
  requires(Regular<codomain_t<P>>);
};

template<typename P>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P>);
  requires(detail::InputDomain<P>);
};

template<typename P>
concept UnaryFunction = requires {
  requires(FunctionalProcedure<P>);
  requires(UnaryProcedure<P>);
};

template<typename P>
concept HomogeneousFunction = requires {
  requires(FunctionalProcedure<P>);
  requires(arity_v<P> > 0);
  requires(detail::HomogenousDomain<P>);
};

template<typename P>
concept Predicate = requires {
  requires(FunctionalProcedure<P>);
  requires(std::same_as<bool, codomain_t<P>>);
};

template<typename P>
concept HomogenousPredicate = requires {
  requires(Predicate<P>);
  requires(HomogeneousFunction<P>);
};

template<typename P>
concept UnaryPredicate = requires {
  requires(Predicate<P>);
  requires(UnaryFunction<P>);
};

template<typename P>
concept Operation = requires {
  requires(HomogeneousFunction<P>);
  requires(std::same_as<std::remove_cvref_t<codomain_t<P>>,
                        std::remove_cvref_t<domain_elem_t<P, 0>>>);
};

template<typename P>
concept Transformation = requires {
  requires(Operation<P>);
  requires(UnaryFunction<P>);
};

template<typename P>
concept BinaryOperation = requires {
  requires(Operation<P>);
  requires(arity_v<P> == 2);
};

template<typename P>
concept AssociativeBinaryOperation = requires {
  requires(BinaryOperation<P>);
  // requires(P is associative)
};

template<typename P>
concept Relation = requires {
  requires(HomogenousPredicate<P>);
  requires(arity_v<P> == 2);
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
