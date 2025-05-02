#pragma once

#include <cstdint>
#include <iterator>
#include <tuple>
#include <type_traits>

#include "based/integer.hpp"

namespace based
{

/* ----- Standard Traits ----- */

template<typename...>
using void_t = void;

template<class T, T v>
struct integral_constant
{
  static constexpr T value = v;

  using value_type = T;
  using type = integral_constant;

  // NOLINTNEXTLINE(*explicit*)
  constexpr operator value_type() const noexcept { return value; }
  constexpr value_type operator()() const noexcept { return value; }
};

using true_type = integral_constant<bool, true>;
using false_type = integral_constant<bool, false>;

// clang-format off

template<class T, class U> struct is_same : false_type { };
template<class T> struct is_same<T, T> : true_type { };
template<class T, class U> constexpr bool is_same_v = is_same<T, U>::value;

template<class T> struct remove_reference { using type = T; };
template<class T> struct remove_reference<T&> { using type = T; };
template<class T> struct remove_reference<T&&> { using type = T; };
template<class T> using remove_reference_t = typename remove_reference<T>::type;

template<class T> struct remove_cv { using type = T; };
template<class T> struct remove_cv<const T> { using type = T; };
template<class T> struct remove_cv<volatile T> { using type = T; };
template<class T> struct remove_cv<const volatile T> { using type = T; };
template<class T> using remove_cv_t = typename remove_cv<T>::type;

template<class T> struct remove_const { using type = T; };
template<class T> struct remove_const<const T> { using type = T; };
template<class T> using remove_const_t = typename remove_const<T>::type;

template<class T> struct remove_volatile { using type = T; };
template<class T> struct remove_volatile<volatile T> { using type = T; };
template<class T> using remove_volatile_t = typename remove_volatile<T>::type;

template<class T> struct remove_cvref { using type = remove_cv_t<remove_reference_t<T>>; };
template<class T> using remove_cvref_t = typename remove_cvref<T>::type;

template<class T> struct remove_pointer { using type = T; };
template<class T> struct remove_pointer<T*> { using type = T; };
template<class T> struct remove_pointer<T* const> { using type = T; };
template<class T> struct remove_pointer<T* volatile> { using type = T; };
template<class T> struct remove_pointer<T* const volatile> { using type = T; };
template<class T> using remove_pointer_t = typename remove_pointer<T>::type;


template<template<class...> class T, class Void, class... Ts>
struct is_instantiable : false_type {};

template<template<class...> class T, class... Ts>
struct is_instantiable<T, void_t<T<Ts...>>, Ts...> : true_type {};

template<template<class...> class T, class... Ts>
inline constexpr auto is_instantiable_v = is_instantiable<T, void, Ts...>::value;

// clang-format on

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
using bare_t = remove_cvref_t<T>;

template<typename T>
concept Semiregular = std::semiregular<T>;

template<typename T>
concept Regular = std::regular<T>;

template<typename T>
concept BareRegular = std::regular<bare_t<T>>;

template<typename T, typename U>
concept SameAs = is_same_v<T, U> && is_same_v<U, T>;

template<typename T, typename U>
concept BareSameAs = SameAs<bare_t<T>, bare_t<U>>;

/* ----- Iterator ----- */

namespace detail
{
template<typename I>
struct iterator_traits
{
  using value_type = I;
  using distance_type = std::uint64_t;
  using pointer_type = I&;
  using reference_type = I*;
};

template<typename I>
  requires std::input_or_output_iterator<I>
struct iterator_traits<I>
{
  using value_type = std::iterator_traits<I>::value_type;
  using distance_type = std::iterator_traits<I>::difference_type;
  using pointer_type = std::iterator_traits<I>::pointer;
  using reference_type = std::iterator_traits<I>::reference;
};

}  // namespace detail

template<typename T>
using iter_value_t = detail::iterator_traits<T>::value_type;

template<typename T>
using iter_dist_t = detail::iterator_traits<T>::distance_type;

template<typename T>
using iter_ptr_t = detail::iterator_traits<T>::pointer;

template<typename T>
using iter_ref_t = detail::iterator_traits<T>::reference;

template<typename T>
concept Readable = requires(T val) {
  requires(Regular<T>);
  typename iter_value_t<T>;
  {
    *val
  } -> BareSameAs<iter_value_t<T>>;
};

template<typename T>
concept Iterator = requires(T val) {
  requires(Regular<T>);
  typename iter_dist_t<T>;
  // requires(Integer<iter_dist_t<T>>);
  {
    ++val
  } -> BareSameAs<T>;
  // successor is not necessarily regular
};

template<typename T>
concept ForwardIterator = requires {
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

/* ----- Function Signature ----- */

template<typename>
struct signature;

template<typename Ret, bool ne, typename... Args>
struct signature<Ret(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, bool ne, typename... Args>
struct signature<Ret (*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = false_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = false_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile & noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = true_type;
  using rvalref_val = false_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename Ret, typename Obj, bool ne, typename... Args>
struct signature<Ret (Obj::*)(Args...) const volatile && noexcept(ne)>
{
  using sig_type = Ret(Args...);
  using arg_type = std::tuple<Args...>;
  using ret_type = Ret;

  using const_val = true_type;
  using volatile_val = true_type;

  using lvalref_val = false_type;
  using rvalref_val = true_type;

  using noexcept_val = integral_constant<bool, ne>;
};

template<typename StaticCallOp>
struct signature_static
{
};

template<typename Ret, bool ne, typename... Args>
struct signature_static<Ret (*)(Args...) noexcept(ne)>
{
  using sig_type = Ret(Args...);
};

template<typename F, typename Op>
using signature_t = typename std::conditional_t<requires(F& func) {
  (void)func.operator();
}, signature_static<Op>, signature<Op>>::sig_type;

/*
template<typename Sig>
class function;

template<typename Ret, typename... Args>
class function<Ret(Args...)>
{
};

template<typename Ret, typename... Args>
function(Ret (*)(Args...)) -> function<Ret(Args...)>;

template<typename F, typename Sig = signature_t<F, decltype(&F::operator())>>
function(F) -> function<Sig>;
*/

/* ----- Callable Interface ----- */

template<typename Sig>
struct callable;

template<typename T>
  requires(std::is_function_v<T>)
struct callable<T> : public signature<std::decay_t<T>>
{
};

template<typename T>
  requires(requires { &std::decay_t<T>::operator(); })
struct callable<T> : public signature<decltype(&T::operator())>
{
};

template<typename T>
  requires(std::is_member_function_pointer_v<std::decay_t<T>>)
struct callable<T> : public signature<remove_pointer_t<T>>
{
};

template<typename T>
concept Callable = is_instantiable_v<callable, T>;

template<Callable T>
using sig_t = typename callable<T>::signature::sig_type;

template<Callable T>
using ret_t = typename callable<T>::signature::ret_type;

/* ----- Function Concepts ----- */

template<typename T>
concept Input = std::is_same_v<T, remove_cvref_t<remove_pointer_t<T>>>
    || std::is_const_v<remove_reference_t<T>>
    || std::is_const_v<remove_pointer_t<T>>;

template<std::size_t idx, typename... Args>
  requires(idx < sizeof...(Args))
using elem_t = std::tuple_element_t<idx, std::tuple<Args...>>;

template<typename... Args>
concept SemiregularDomain = (Semiregular<remove_cvref_t<Args>> && ...);

template<typename... Args>
concept RegularDomain = (Regular<remove_cvref_t<Args>> && ...);

template<typename... Args>
concept InputDomain = (Input<Args> && ...);

template<typename... Args>
concept HomogeneousDomain = (SameAs<elem_t<0, Args...>, Args> && ...);

template<typename P, typename... Args>
concept Invocable = std::invocable<P, Args...>;

template<typename P, typename Ret, typename... Args>
concept Procedure = requires {
  requires(Invocable<P, Args...>);
  requires(SameAs<void, Ret> || SameAs<Ret, std::invoke_result_t<P, Args...>>);
};

template<typename P, typename Ret, typename Arg>
concept UnaryProcedure = Procedure<P, Ret, Arg>;

template<typename P, typename Ret, typename... Args>
concept RegularProcedure = requires {
  requires(Procedure<P, void, Args...>);
  requires(SameAs<void, Ret> || std::convertible_to<std::invoke_result_t<P, Args...>, Ret>);
  requires(RegularDomain<Args...>);
  requires(Regular<Ret>);
};

template<typename P, typename Ret, typename... Args>
concept FunctionalProcedure = requires {
  requires(RegularProcedure<P, Ret, Args...>);
  requires(InputDomain<Args...>);
};

template<typename P, typename Ret, typename Arg>
concept UnaryFunction = requires {
  requires(FunctionalProcedure<P, Ret, Arg>);
  requires(UnaryProcedure<P, Ret, Arg>);
};

template<typename P, typename Ret, typename... Args>
concept HomogeneousFunction = requires {
  requires(FunctionalProcedure<P, Ret, Args...>);
  requires(sizeof...(Args) > 0);
  requires(HomogeneousDomain<Args...>);
};

template<typename P, typename... Args>
concept Predicate = FunctionalProcedure<P, bool, Args...>;

template<typename P, typename... Args>
concept HomogeneousPredicate = requires {
  requires(Predicate<P, Args...>);
  requires(HomogeneousFunction<P, bool, Args...>);
};

template<typename P, typename Arg>
concept UnaryPredicate = requires {
  requires(Predicate<P, Arg>);
  requires(UnaryFunction<P, bool, Arg>);
};

template<typename P, typename... Args>
concept Operation = HomogeneousFunction<P, elem_t<0, Args...>, Args...>;

template<typename P, typename Ret, typename Arg>
concept Transformation = requires {
  requires(Operation<P, Ret, Arg>);
  requires(UnaryFunction<P, Ret, Arg>);
};

template<typename P, typename Arg>
concept BinaryOperation = Operation<P, Arg, Arg>;

template<typename P, typename Arg>
concept AssociativeBinaryOperation = Operation<P, Arg, Arg>;

template<typename P, typename Arg>
concept Relation = HomogeneousPredicate<P, Arg, Arg>;

/* ----- Iterator variants ----- */

template<typename P, typename Ret, typename I>
concept IterUnaryProcedure = requires {
  requires(Iterator<I>);
  requires(UnaryProcedure<P, Ret, iter_value_t<I>>);
};

template<typename P, typename Ret, typename I>
concept IterUnaryFunction = requires {
  requires(Iterator<I>);
  requires(UnaryFunction<P, Ret, iter_value_t<I>>);
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

template<typename P, typename Ret, typename... I>
concept IterOperation = requires {
  requires(Iterator<I> && ...);
  requires(Operation<P, iter_value_t<I>...>);
};

template<typename P, typename Ret, typename I>
concept IterBinaryOperation = requires {
  requires(Iterator<I>);
  requires(BinaryOperation<P, iter_value_t<I>>);
};

template<typename P, typename I>
concept IterRelation = requires {
  requires(Iterator<I>);
  requires(Relation<P, iter_value_t<I>>);
};

}  // namespace based
