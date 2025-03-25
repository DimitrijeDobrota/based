#pragma once

#include <tuple>
#include <type_traits>

namespace based
{

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept Input =
    std::same_as<T,
                 std::remove_volatile_t<
                     std::remove_reference_t<std::remove_pointer_t<T>>>>
    || (std::is_lvalue_reference_v<T>
        && std::is_const_v<std::remove_reference_t<T>>);

template<typename P, typename... Args>
concept Invokable = std::invocable<P, Args...>;

template<typename Fun>
concept FreeProcedure = std::is_function_v<Fun>;

template<typename Fun>
concept MemberProcedure = std::is_member_function_pointer_v<std::decay_t<Fun>>;

template<typename Fun>
concept FunctorProcedure = std::is_class_v<std::decay_t<Fun>>
    && requires(Fun&& t) { &std::decay_t<Fun>::operator(); };

template<typename P>
concept Procedure =
    FreeProcedure<P> || MemberProcedure<P> || FunctorProcedure<P>;

template<class>
struct is_regular_tuple : std::false_type
{
};

template<template<class...> class Tuple, class... Types>
  requires(Regular<std::remove_cvref_t<Types>> && ...)
struct is_regular_tuple<Tuple<Types...>> : std::true_type
{
};

template<class>
struct is_input_tuple : std::false_type
{
};

template<class T>
inline constexpr bool is_regular_tuple_v = is_regular_tuple<T>::value;

template<class T>
concept RegularTuple = is_regular_tuple_v<T>;

template<template<class...> class Tuple, class... Types>
  requires(Input<Types> && ...)
struct is_input_tuple<Tuple<Types...>> : std::true_type
{
};

template<class T>
inline constexpr bool is_input_tuple_v = is_input_tuple<T>::value;

template<class T>
concept InputTuple = is_input_tuple_v<T>;

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

template<FunctorProcedure P>
struct domain<P>
{
  using type = signature<decltype(&std::decay_t<P>::operator())>::arg_type;
};

template<FreeProcedure P>
struct domain<P>
{
  using type = signature<P>::arg_type;
};

template<MemberProcedure P>
struct domain<P>
{
  using type = signature<std::decay_t<P>>::arg_type;
};

template<typename P>
using domain_t = domain<P>::type;

template<typename>
struct codomain;

template<FunctorProcedure P>
struct codomain<P>
{
  using type = signature<decltype(&std::decay_t<P>::operator())>::ret_type;
};

template<FreeProcedure P>
struct codomain<P>
{
  using type = signature<P>::ret_type;
};

template<MemberProcedure P>
struct codomain<P>
{
  using type = signature<std::decay_t<P>>::ret_type;
};

template<typename P>
using codomain_t = typename codomain<P>::type;

template<typename P>
struct arity
{
  static constexpr auto value = std::tuple_size<domain_t<P>>::value;
};

template<typename P>
inline constexpr auto arity_v = arity<P>::value;

template<typename P, std::size_t Idx>
  requires requires { Idx < arity_v<P>; }
struct domain_elem
{
  using type = std::tuple_element_t<Idx, domain_t<P>>;
};

template<typename P, std::size_t Idx>
using domain_elem_t = typename domain_elem<P, Idx>::type;

template<typename P>
concept RegularProcedure = requires {
  requires(Procedure<P>);
  requires(RegularTuple<domain_t<P>>);
  requires(Regular<codomain_t<P>>);
};

template<typename P>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P>);
  requires(InputTuple<domain_t<P>>);
};

}  // namespace based
