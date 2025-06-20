#define CATCH_CONFIG_RUNTIME_STATIC_REQUIRE

#include <stdexcept>

#include "based/utility/scopeguard.hpp"

#include <catch2/catch_test_macros.hpp>

// NOLINTBEGIN(*cognitive-complexity*)

struct Set
{
  explicit Set(int& val)
      : m_val(&val)
  {
  }

  void operator()() const { *m_val = 1; }

private:
  int* m_val;
};

template class based::Scopeguard<Set>;

TEST_CASE("manual", "[utility/scopeguard]")
{
  SECTION("commit")
  {
    int test = 0;
    try {
      based::Scopeguard guard = Set(test);
      guard.commit();
    } catch (...) {
      REQUIRE(false);
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("no commit")
  {
    int test = 0;
    try {
      based::Scopeguard guard = Set(test);  // NOLINT(*const*)
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }
}

TEST_CASE("on success", "[utility/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::ScopeguardSuccess guard = Set(test);
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::ScopeguardSuccess guard = Set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }
}

TEST_CASE("on failure", "[utility/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::ScopeguardFailure guard = Set(test);
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 0);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::ScopeguardFailure guard = Set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      REQUIRE(true);
    }
    REQUIRE(test == 1);
  }
}

TEST_CASE("exit", "[utility/scopeguard]")
{
  SECTION("success")
  {
    int test = 0;
    try {
      const based::ScopeguardExit guard = Set(test);
    } catch (...) {
      REQUIRE(false);
    }
    REQUIRE(test == 1);
  }

  // breaks coverage for some reason
  SECTION("failure")
  {
    int test = 0;
    try {
      const based::ScopeguardExit guard = Set(test);
      throw std::runtime_error {"should not leak"};
    } catch (...) {
      test *= 1;
    }
    REQUIRE(test == 1);
  }
}

// NOLINTEND(*cognitive-complexity*)
