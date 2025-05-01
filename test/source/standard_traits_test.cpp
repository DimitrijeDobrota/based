// #define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/type_traits.hpp"

// NOLINTBEGIN(*array*)

using based::SameAs;

TEST_CASE("remove_const", "[type_traits/remove_const]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_const_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int>, volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const volatile int>, volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_const_t<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
}

TEST_CASE("remove_volatile", "[type_traits/remove_volatile]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const int>, const int>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const int[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const volatile int>, const int>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const volatile int[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_volatile_t<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
}

TEST_CASE("remove_cv", "[type_traits/remove_cv]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int&>, int&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int&&>, int&&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int(&)[2]>, int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int(&&)[2]>, int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const int&>, const int&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const int(&)[2]>, const int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int&>, volatile int&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int&&>, volatile int&&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int(&)[2]>, volatile int(&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<volatile int(&&)[2]>, volatile int(&&)[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const volatile int&>, volatile const int&>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cv_t<const volatile int(&)[2]>, volatile const int(&)[2]>);
  // clang-format on
}

TEST_CASE("remove_reference", "[type_traits/remove_reference]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const int>, const int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const int&>, const int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const int[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const int(&)[2]>, const int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int>,volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int&>, volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int&&>, volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int(&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<volatile int(&&)[2]>, volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const volatile int>, const volatile int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const volatile int&>, volatile const int>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const volatile int[2]>, const volatile int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_reference_t<const volatile int(&)[2]>, volatile const int[2]>);
  // clang-format on
}

TEST_CASE("remove_cvref", "[type_traits/remove_cvref]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int&&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<int(int)>, int(int)>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int&&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int(&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<volatile int(&&)[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int&>, int>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int[2]>, int[2]>);
  STATIC_REQUIRE(SameAs<based::remove_cvref_t<const volatile int(&)[2]>, int[2]>);
  // clang-format on
}

TEST_CASE("remove_pointer", "[type_traits/remove_pointer]")
{
  // clang-format off
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int>, int>);
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int*>, int>);
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int**>, int*>);
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int* const>, int>);
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int* volatile>, int>);
  STATIC_REQUIRE(SameAs<based::remove_pointer_t<int* const volatile>, int>);
  // clang-format on
}

// NOLINTEND(*array*)
