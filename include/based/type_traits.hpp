#pragma once

#include <cstdint>
#include <tuple>
#include <type_traits>

#include "based/integer.hpp"

namespace based
{

template<typename T>
concept Integer = requires(T n) {
  successor(n);
  predecesor(n);
  twice(n);
  half(n);
  positive(n);
  negative(n);
  zero(n);
  one(n);
  even(n);
  odd(n);
};

template<typename T>
concept Regular = std::regular<T>;

template<typename T, typename U>
concept SameAs = std::is_same_v<T, U> && std::is_same_v<U, T>;

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

template<class T>
concept RegularTuple = is_regular_tuple_v<T>;

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

template<class T>
concept InputTuple = is_input_tuple_v<T>;

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

template<class T>
concept HomogenousTuple = is_input_tuple_v<T>;

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

}  // namespace detail

template<typename P>
using domain_t = detail::domain<P>::type;

template<typename P>
using codomain_t = typename detail::codomain<P>::type;

template<typename P>
inline constexpr auto arity_v = std::tuple_size<domain_t<P>>::value;

template<typename P, std::size_t Idx>
  requires requires { Idx < arity_v<P>; }
using domain_elem_t = std::tuple_element_t<Idx, domain_t<P>>;

template<typename P>
using distance_t = std::uint64_t;

template<typename P>
concept Procedure = detail::FreeProcedure<P> || detail::MemberProcedure<P>
    || detail::FunctorProcedure<P>;

template<typename P>
concept RegularProcedure = requires {
  requires(Procedure<P>);
  requires(detail::RegularTuple<domain_t<P>>);
  requires(Regular<codomain_t<P>>);
};

template<typename P>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P>);
  requires(detail::InputTuple<domain_t<P>>);
};

template<typename P>
concept UnaryFunction = requires {
  requires(FunctionalProcedure<P>);
  requires(arity_v<P> == 1);
};

template<typename P>
concept HomogeneousFunction = requires {
  requires(FunctionalProcedure<P>);
  requires(arity_v<P> > 0);
  requires(detail::HomogenousTuple<domain_t<P>>);
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

}  // namespace based
