#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include "based/trait/signature.hpp"

#include <catch2/catch_test_macros.hpp>

#include "based/concept/is/same.hpp"
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

TEST_CASE("free function", "[trait/Signature]")
{
  using Sig = based::Signature<decltype(free_func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("free function noexcept", "[trait/Signature]")
{
  using Sig = based::Signature<decltype(free_func_noexcept)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("empty", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("volatile", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("noexcept", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const noexcept", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("volatile noexcept", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile noexcept", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) & noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("volatile lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("noexcept lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) & noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const noexcept lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("volatile noexcept lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile noexcept lvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) && noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const&& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("volatile rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile&& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(false);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::NoexceptVal>);
}

TEST_CASE("noexcept rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) && noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const noexcept rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const&& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("volatile noexcept rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) volatile&& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

TEST_CASE("const volatile noexcept rvalref", "[trait/Signature]")
{
  struct Test
  {
    int func(const double& a, int&& b) const volatile&& noexcept(true);
  };

  using Sig = based::Signature<decltype(&Test::func)>;
  STATIC_REQUIRE(SameAs<int(const double&, int&&), Sig::SigType>);
  STATIC_REQUIRE(SameAs<std::tuple<const double&, int&&>, Sig::ArgType>);
  STATIC_REQUIRE(SameAs<int, Sig::RetType>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::ConstVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::VolatileVal>);
  STATIC_REQUIRE(SameAs<based::FalseType, Sig::LvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::RvalrefVal>);
  STATIC_REQUIRE(SameAs<based::TrueType, Sig::NoexceptVal>);
}

// NOLINTEND(*cognitive-complexity*)
