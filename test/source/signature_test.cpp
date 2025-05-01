#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/type_traits.hpp"

// NOLINTBEGIN(*cognitive-complexity*)

namespace
{

// NOLINTNEXTLINE (*needed*)
int free_func(const double& a, int&& b) noexcept(false)
{
  return static_cast<int>(a + b);
}

// NOLINTNEXTLINE (*needed*)
int free_func_noexcept(const double& a, int&& b) noexcept(true)
{
  return static_cast<int>(a + b);
}

}  // namespace

using based::SameAs;

TEST_CASE("free function", "[type_traits/signature]")
{
  using sig = based::signature<decltype(free_func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("free function noexcept", "[type_traits/signature]")
{
  using sig = based::signature<decltype(free_func_noexcept)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("empty", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) & noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) & noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept lvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) && noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) && noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept rvalref", "[type_traits/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(SameAs<int, sig::ret_type>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::const_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::volatile_val>);
  STATIC_REQUIRE(SameAs<based::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(SameAs<based::true_type, sig::noexcept_val>);
}

// NOLINTEND(*cognitive-complexity*)
