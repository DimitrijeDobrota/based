#pragma once

#include <tuple>
#include <type_traits>

namespace based
{

template<typename T>
concept Regular = std::regular<T>;

template<typename>
struct is_tuple : std::false_type
{
};

template<typename... T>
struct is_tuple<std::tuple<T...>> : std::true_type
{
};

template<typename T>
inline constexpr bool is_tuple_v = is_tuple<T>::value;

template<class>
struct is_regular_tuple : std::false_type
{
};

template<template<class...> class Tuple, class... Types>
  requires(Regular<Types> && ...)
struct is_regular_tuple<Tuple<Types...>> : std::true_type
{
};

template<class T>
inline constexpr bool is_regular_tuple_v = is_regular_tuple<T>::value;

template<class T>
concept RegularTuple = is_regular_tuple_v<T>;

template<typename P>
struct domain
{
  using type = std::remove_reference_t<P>::input_types;
};

template<typename T>
using domain_t = typename domain<T>::type;

template<typename P>
struct codomain
{
  using type = std::remove_reference_t<P>::output_type;
};

template<typename T>
using codomain_t = typename codomain<T>::type;

template<typename P>
concept Procedure = requires {
  typename domain_t<P>;
  typename codomain_t<P>;
  requires(is_tuple_v<domain_t<P>>);
};

template<Procedure P>
struct arity
{
  static constexpr auto value = std::tuple_size<domain_t<P>>::value;
};

template<Procedure P>
inline constexpr auto arity_v = arity<P>::value;

template<Procedure P, std::size_t Idx>
  requires requires { Idx < arity_v<P>; }
struct domain_elem
{
  using type = std::tuple_element_t<Idx, domain_t<P>>;
};

template<Procedure P, std::size_t Idx>
using domain_elem_t = typename domain_elem<P, Idx>::type;

template<typename P>
concept RegularProcedure = requires {
  requires(Procedure<P>);
  requires(RegularTuple<domain_t<P>>);
  requires(Regular<codomain_t<P>>);
};

/*
template<typename P>
concept FunctionalProcedure = requires { requires(RegularProcedure<P>); };
*/

}  // namespace based
