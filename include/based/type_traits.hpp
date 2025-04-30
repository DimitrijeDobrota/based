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
concept Readable = requires(T val) {
  requires(Regular<T>);
  typename iter_value_t<T>;
  { *val } -> BareSameAs<iter_value_t<T>>;
};

template<typename T>
concept Iterator = requires(T val) {
    requires(Regular<T>);
    typename iter_dist_t<T>;
    // requires(Integer<iter_dist_t<T>>);
    { ++val } -> BareSameAs<T>;
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

template<std::size_t idx, typename... Args>
  requires(idx < sizeof...(Args))
using elem_t = std::tuple_element_t<idx, std::tuple<Args...>>;

template<typename... Args>
concept RegularDomain =
    requires { requires(Regular<std::remove_cvref_t<Args>> && ...); };

template<typename... Args>
concept InputDomain = requires { requires(Input<Args> && ...); };

template<typename... Args>
concept HomogeneousDomain = detail::is_homogeneous_domain<Args...>::value;

template<typename T>
using distance_t = std::uint64_t;

template<typename P, typename Ret, typename... Args>
concept Procedure = requires {
  requires(std::invocable<P, Args...>);
  requires(std::same_as<void, Ret> || std::same_as<Ret, std::invoke_result_t<P, Args...>>);
};

template<typename P, typename Ret, typename Arg>
concept UnaryProcedure = Procedure<P, Ret, Arg>;

template<typename P, typename Ret, typename... Args>
concept RegularProcedure = requires {
  requires(Procedure<P, Ret, Args...>);
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
