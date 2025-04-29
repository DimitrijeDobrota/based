#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <catch2/catch_test_macros.hpp>

#include "based/template.hpp"

namespace
{

int free_func(const double& a, int&& b) noexcept(false)  // NOLINT
{
  return static_cast<int>(a + std::move(b));  // NOLINT
}

int free_func_noexcept(const double& a, int&& b) noexcept(true)  // NOLINT
{
  return static_cast<int>(a + std::move(b));  // NOLINT
}

}  // namespace

TEST_CASE("free function", "[template/signature]")
{
  using sig = based::signature<decltype(free_func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("free function noexcept", "[template/signature]")
{
  using sig = based::signature<decltype(free_func_noexcept)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("empty", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) & noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) & noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept lvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) && noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("volatile rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("const volatile rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(false);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::noexcept_val>);
}

TEST_CASE("noexcept rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) && noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const noexcept rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("volatile noexcept rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) volatile&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}

TEST_CASE("const volatile noexcept rvalref", "[template/signature]")
{
  struct test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(true);
  };

  using sig = based::signature<decltype(&test::func)>;
  STATIC_REQUIRE(std::same_as<int(const double&, int&&), sig::sig_type>);
  STATIC_REQUIRE(std::same_as<std::tuple<const double&, int&&>, sig::arg_type>);
  STATIC_REQUIRE(std::same_as<int, sig::ret_type>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::const_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::volatile_val>);
  STATIC_REQUIRE(std::same_as<std::false_type, sig::lvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::rvalref_val>);
  STATIC_REQUIRE(std::same_as<std::true_type, sig::noexcept_val>);
}
